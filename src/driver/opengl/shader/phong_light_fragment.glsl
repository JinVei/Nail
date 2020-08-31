#version 330 core
out vec4 FragColor;
in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

struct Material {
    sampler2D diffuseMap;
    sampler2D specularMap;
    float     shininess;

    vec3 ambient_vec;
    vec3 diffuse_vec;
    vec3 specular_vec;
};

struct Light {
    int lightType;

    vec3 position;
    vec3 direction;

    float constant;
    float linear;
    float quadratic;

    float cutOff;
    float outerCutOff;
}

#define MAX_LIGHT_ARRAY_LENGTH 8

#define 1 LIGHT_TYPE_DIRECTION
#define 2 LIGHT_TYPE_POINT
#define 3 LIGHT_TYPE_SPOT

// @param
uniform Light lights[MAX_LIGHT_ARRAY_LENGTH];
// @param
uniform int lightArraylen;
// @param
uniform Material material;
// @param
uniform vec3 viewPos;

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 CalcSpotLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
void main()
{
    if (MAX_LIGHT_ARRAY_LENGTH < lightArraylen) {
        lightArraylen = MAX_LIGHT_ARRAY_LENGTH;
    }

    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);

    vec3 color = vec3(0);
    for (int i=0; i<lightArraylen; i++)
    {
        if (lights[i].lightType == LIGHT_TYPE_POINT) 
        {
            color += CalcPointLight(lights[i], norm, FragPos, viewDir);
        }
        else if (lights[i].lightType == LIGHT_TYPE_DIRECTION)
        {
            color += CalcDirLight(lights[i], norm, viewDir);
        }
        else if (lights[i].lightType == LIGHT_TYPE_SPOT)
        {
            color += CalcSpotLight(lights[i], norm, viewDir);
        }
    }
    
    FragColor = vec4(color, 1.0);
}

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

    vec3 ambient  = light.ambient  * vec3(texture(material.diffuseMap, TexCoords));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(material.diffuseMap, TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(material.specularMap, TexCoords));
    return (ambient + diffuse + specular);
}

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);

    float distance    = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

    float intensity = 1.0;

    float diff = max(dot(normal, lightDir), 0.0);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess); 

    vec3 ambient  = light.ambient  * vec3(texture(material.diffuseMap, TexCoords));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(material.diffuseMap, TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(material.specularMap, TexCoords));

    return (ambient + diffuse*intensity + specular*intensity) * attenuation;
}

vec3 CalcSpotLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);

    float distance    = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

    float intensity = 1.0;

    if (light.direction.x != 0.0 || light.direction.y != 0.0 || light.direction.z != 0.0)
    {
         float theta     = dot(lightDir, normalize(-light.direction));
         float epsilon   = light.cutOff - light.outerCutOff;
         intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0); 
    }

    float diff = max(dot(normal, lightDir), 0.0);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess); 

    vec3 ambient  = light.ambient  * vec3(texture(material.diffuseMap, TexCoords));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(material.diffuseMap, TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(material.specularMap, TexCoords));

    return (ambient + diffuse*intensity + specular*intensity) * attenuation;
}

