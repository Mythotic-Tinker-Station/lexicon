function split(s, delimiter)
    result = {}
    for match in (s..delimiter):gmatch("(.-)"..delimiter) do
        table.insert(result, match)
    end
    return result
end

local canvas = love.graphics.newCanvas(640, 480)

function love.load(arg)
    
    -- load font
    local font = love.graphics.newFont("/fonts/AmazDooMLeft.ttf", 60)
    love.graphics.setFont(font)
    
    -- load vignette
    local vignette = love.graphics.newImage("/effects/vignette.png")
    
    
    -- read title file
    local file_titles = io.open(love.filesystem.getSourceBaseDirectory() .. "/src/titles.txt")
    local title_list = {}
    
    local title = file_titles:read("*line")
    local title = file_titles:read("*line") 
    title = file_titles:read("*line")
    while title ~= nil do
        title = split(title, "=")
        title_list[#title_list+1] = { title[1], title[2], title[3] }
        title = file_titles:read("*line")
    end
    file_titles:close()
    
    -- do screens
    for k, v in ipairs(title_list) do
        exists = love.graphics.newImage("/screens/" .. v[1] .. ".png")
        if exists == nil then
            error("Could not file screen: " .. v[1]) 
        else
            
            print("Found screen: " .. v[1] .. ", with title: " .. v[2] .. ", with color: " .. v[3])
            
            love.graphics.setColor(255, 255, 255, 255)
            love.graphics.setCanvas(canvas)
            
                if v[3] == "r" then love.graphics.setColor(255, 160, 160, 255) end
                if v[3] == "g" then love.graphics.setColor(160, 255, 160, 255) end
                if v[3] == "b" then love.graphics.setColor(160, 160, 255, 255) end
                love.graphics.draw(exists)

                love.graphics.setColor(255, 255, 255, 255)
                love.graphics.draw(vignette)
                
                local screen_cx = 320
                local text_l = font:getWidth(v[2])/2
                local text_cx = screen_cx-text_l
                
                love.graphics.print(v[2], text_cx, 16)
                
            love.graphics.setCanvas()
            love.graphics.setColor(255, 255, 255, 255)
            
            local imgdata = canvas:newImageData()
            local pngdata = imgdata:encode("png"):getString()
            local pngfile = io.open(love.filesystem.getSourceBaseDirectory() .. "/src/results/" .. v[1] .. ".png", "w+b")
            pngfile:write(pngdata)
            pngfile:close()
        end
    end
end



function love.update(dt)
    
end



function love.draw()
    love.graphics.setColor(255, 255, 255, 255)
    love.graphics.draw(canvas)
end


















