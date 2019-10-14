function split(s, delimiter)
    result = {}
    for match in (s..delimiter):gmatch("(.-)"..delimiter) do
        table.insert(result, match)
    end
    return result
end

local canvas = love.graphics.newCanvas(640, 720)

function love.load(arg)
    
    -- load font
    local font = love.graphics.newFont("/fonts/Doom.ttf", 30)
    love.graphics.setFont(font)
    
    -- load vignette
    local vignette = love.graphics.newImage("/effects/vignette.png")
    
    -- load border
    local border = love.graphics.newImage("/effects/border.png")
    
    
    -- read title file
    local file_titles = io.open(love.filesystem.getSourceBaseDirectory() .. "/src/titles.txt")
    local title_list = {}
    
    file_titles:read("*line")
    file_titles:read("*line")
    local title = file_titles:read("*line")
    while title ~= nil do
        title = split(title, "=")
        title_list[#title_list+1] = { title[1], title[2], title[3], title[4] }
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
            
                love.graphics.clear(0, 0, 0, 0)
                
                -- draw the screen
                --if v[3] == "r" then love.graphics.setColor(255, 160, 160, 255) end
                --if v[3] == "g" then love.graphics.setColor(160, 255, 160, 255) end
                --if v[3] == "b" then love.graphics.setColor(160, 160, 255, 255) end
                --if v[3] == "w" then love.graphics.setColor(255, 255, 255, 255) end
                love.graphics.setColor(255, 255, 255, 255)
                love.graphics.draw(exists)
                

                -- draw the vignette
                love.graphics.setColor(0, 0, 0, 128)
                love.graphics.draw(vignette)
                

                -- draw the border
                if v[3] == "r" then love.graphics.setColor(128, 64, 64, 255) end
                if v[3] == "g" then love.graphics.setColor(64, 128, 64, 255) end
                if v[3] == "b" then love.graphics.setColor(64, 64, 128, 255) end
                if v[3] == "w" then love.graphics.setColor(255, 255, 255, 255) end
                love.graphics.draw(border)             
                
                -- draw the text
                if(v[2] ~= "STATIC") then

                    local screen_cx = 320
                    local text_l = font:getWidth(v[2])/2
                    local text_cx = screen_cx-text_l
                    
                    love.graphics.setColor(255, 255, 255, 255)
                    love.graphics.print(v[2], text_cx, 16)
                    
                    if(v[4] == "wip")  then
                        local text_l = font:getWidth("- Work In Progress -")/2
                        local text_cx = screen_cx-text_l
                        love.graphics.print("- Work In Progress -", text_cx, 480-64)                            
                    end
                end
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


















