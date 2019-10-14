
function love.load(arg)
    
    class = require("m_30log")
    streamwriter = require("cls_streamwriter")
    wadreader = require("wad")

    
    -- inti filesystem stuff
    require("lovefs")
    fs = lovefs()
    local path_pk3 = love.filesystem.getSource() .. "/../../../pk3"
    fs:cd(path_pk3)
    
    -- get all wad files
    local wads = {}
    for i, v in ipairs(fs.files) do
        if v:sub(-4) == ".wad" or v:sub(-4) == ".WAD" then
            wads[#wads+1] = { path_full = path_pk3 .. "/" .. v, name = v, path = path_pk3 .. "/" }
        end
    end

    -- for each wad file
    local w = 1
    while w <= #wads do

        -- for each lump
        local lumps = wadreader:load(wads[w].path_full)

        for l = 1, #lumps do
            if lumps[l].format == "MapDoom" or lumps[l].format == "MapHexen" or lumps[l].format == "MapUDMF" then
                
                local data = streamwriter(wads[w].path .. "Maps/" .. lumps[l].name .. ".wad")
                
                -- header
                data:writeString("PWAD")
                data:write32(lumps[l].size)
                data:write32(0)
                local filedatepos = data.file:seek()+4
                
                -- lump data
                for i = 0, lumps[l].size-1 do
                    if lumps[l+i].size > 0 then
                        data:writeString(lumps[l+i].data)
                        lumps[l+i].offset = filedatepos
                        filedatepos = data.file:seek()
                    else
                        lumps[l+i].offset = 0
                    end
                end
            
                -- directory
                data:write32(0)
                data:write32(0)
                data:writeStringPad("MAP01", 8)
                
                for i = 1, lumps[l].size-1 do
                    data:write32(lumps[l+i].offset)
                    data:write32(lumps[l+i].size)
                    data:writeStringPad(lumps[l+i].name, 8)
                end

                local dirpos = (data.file:seek()-(lumps[l].size * 16))
                data.file:seek("set", 8)
                data:write32(dirpos)

                data:close()
            end
        end

        w = w + 1
    end

end

function love.update(dt)
    
end

function love.draw()

end


















