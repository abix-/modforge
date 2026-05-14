// Address: 0x140226e70
// Ghidra name: FUN_140226e70
// ============ 0x140226e70 FUN_140226e70 (size=140) ============


float FUN_140226e70(longlong param_1,undefined8 param_2)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  undefined4 local_78;

  undefined4 local_74;

  undefined8 local_70;

  undefined4 local_68;

  uint local_64;

  undefined1 local_58 [20];

  undefined8 local_44;

  undefined4 local_3c;

  

  lVar1 = *(longlong *)(param_1 + 0x680);

  cVar2 = FUN_140226b40(lVar1,param_2,local_58);

  if (cVar2 != '\0') {

    local_70 = local_44;

    local_68 = local_3c;

    local_64 = 0;

    local_78 = 0xb;

    local_74 = 0x18;

    iVar3 = (**(code **)(lVar1 + 0x28))(&local_78);

    if ((iVar3 == 0) && (local_64 != 0)) {

      return (float)local_64 / DAT_14039ca60;

    }

  }

  return DAT_14039ca44;

}




