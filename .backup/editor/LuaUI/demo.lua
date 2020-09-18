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

function onDraw() 
    imgui.Begin("lua ui")
    imgui.Text("a text")
    imgui.End()
end