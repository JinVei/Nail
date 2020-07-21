-- UI::View::Text
function register(state)
    state.MenuPath = "file/open"
end

function initUI(state)
    --state.ui.add(UI::View::Text)
end

function beforDraw(state)

end

function afterDraw(state)

end

local click_cnt = 0
local in_choose = false
function onDraw() 
    imgui.Begin("lua ui")
    imgui.Text("a text")
    in_choose = imgui.CheckBox("show button",in_choose)
    if  in_choose then
        if imgui.Button("a button:"..tostring(click_cnt)) then
            click_cnt = click_cnt + 1
        end
    end

    imgui.End()
end