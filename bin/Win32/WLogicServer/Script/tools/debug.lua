local type = type
local tostring = tostring
local tableinsert = table.insert
local tableconcat = table.concat


-- 调试打印函数,itype=nil 且 _LUA_DEBUG=true 输出,itype 为真时全输出,由全局 _DEBUG 控制
function look(t, itype)
	if not _LUA_DEBUG and not itype then return end
	
	local sign = {}
	local function _print(t, stimes, pointer)
		local space = ""
		for i=1,stimes do
			space = space.."    "
		end
			
		if type(t) == "table" then
			sign[t] = pointer
			local temp = {}
			tableinsert(temp,space.."{\n")
			for k,v in pairs(t)do
				local key = type(k) == "string" and k or "["..tostring(k).."]" 
				if type(v) ~= "table" then
					local k_v = type(v) == "string" and space.."    "..key.."=".."\""..v.."\""..",\n" or space.."    "..key.."="..tostring(v)..",\n"
					tableinsert(temp, k_v)
				else
				    local psign = sign[v]
				    if psign then
						tableinsert(temp, space.."    "..key.."="..psign..",\n")
					else
					    tableinsert(temp, space.."    "..key.."=\n")
						tableinsert(temp, _print(v, stimes+1, pointer.."."..tostring(k)))
					end
				end
			end
			return tableconcat(temp)..space.."},\n"
		else
			return tostring(t)
		end	
	end
	
	Log(_print(t, 0, "_@self"))
end

function lookx(t, itype)
	if not _LUA_DEBUG and not itype then return end
	
	local sign = {}
	local function _print(t, stimes, pointer)
		local space = ""
		for i=1,stimes do
			space = space.."    "
		end
			
		if type(t) == "table" then
			sign[t] = pointer
			Log(space.."{")
			for k,v in pairs(t)do
				local key = type(k) == "string" and k or "["..tostring(k).."]" 
				if type(v) ~= "table" then
					local k_v = type(v) == "string" and space.."    "..key.."=".."\""..v.."\"".."," or space.."    "..key.."="..tostring(v)..","
					Log(k_v)
				else
				    local psign = sign[v]
				    if psign then
						Log(space.."    "..key.."="..psign..",")
					else
					    Log(space.."    "..key.."=")
						_print(v, stimes+1, pointer.."."..tostring(k))
					end
				end
			end
			Log(space.."},")
		else
			Log(tostring(t))
		end	
	end
	
	_print(t, 0, "_@self")
end