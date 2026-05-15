// Address: 0x140288400
// Ghidra name: FUN_140288400
// ============ 0x140288400 FUN_140288400 (size=93) ============


undefined8 FUN_140288400(longlong param_1,int param_2)



{

  int iVar1;

  undefined8 uVar2;

  undefined4 local_28;

  undefined8 local_24;

  undefined4 local_1c;

  uint local_18;

  

  local_28 = 0x14;

  local_1c = 0;

  local_24 = 0x10;

  local_18 = (uint)(param_2 != 0);

  iVar1 = (**(code **)(*(longlong *)**(undefined8 **)(param_1 + 0x28) + 0x30))

                    ((longlong *)**(undefined8 **)(param_1 + 0x28),9,&local_28);

  if (iVar1 < 0) {

    uVar2 = FUN_1402878d0("Setting autocenter",iVar1);

    return uVar2;

  }

  return 1;

}




