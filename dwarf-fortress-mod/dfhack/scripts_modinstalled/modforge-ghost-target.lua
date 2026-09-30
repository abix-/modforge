-- Print the exact in-process address Modforge must watch to find native ghost
-- creation. Select a unit before running, or pass a unit ID.

local args = {...}
local unit

if args[1] then
    local unit_id = tonumber(args[1])
    if not unit_id then
        qerror('unit ID must be an integer')
    end
    unit = df.unit.find(unit_id)
else
    unit = dfhack.gui.getSelectedUnit(true)
end

if not unit then
    qerror('select a unit or pass a valid unit ID')
end

local size, address = df.sizeof(unit.flags3)
if not address then
    qerror('DFHack did not expose the flags3 address')
end

print(('unit_id=%d name=%s'):format(
    unit.id,
    dfhack.units.getReadableName(unit)))
print(('flags3_address=0x%x size=%d whole=0x%x ghostly=%s'):format(
    address,
    size,
    unit.flags3.whole,
    tostring(unit.flags3.ghostly)))
print(('killed=%s inactive=%s own_group=%s'):format(
    tostring(unit.flags2.killed),
    tostring(unit.flags1.inactive),
    tostring(dfhack.units.isOwnGroup(unit))))
print('ghostly_mask=0x1000')
