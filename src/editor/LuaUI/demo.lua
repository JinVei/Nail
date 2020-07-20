-- UI::View::Text
function register(state)
    local state.MenuPath = "file/open"
end

function initUI(state)
    state.ui.add(UI::View::Text)
end

function beforDraw(state)

end

function afterDraw(state)

end