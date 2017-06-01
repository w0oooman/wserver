

--上线
function OnPlayerOnline(sid)
    Log("OnPlayerOnline sid="..tostring(sid))

end

--下线
function OnServerOffline(sid)
    Log("OnServerOffline sid="..tostring(sid))
    
end