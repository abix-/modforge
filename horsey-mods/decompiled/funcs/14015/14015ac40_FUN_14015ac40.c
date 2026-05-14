// Address: 0x14015ac40
// Ghidra name: FUN_14015ac40
// ============ 0x14015ac40 FUN_14015ac40 (size=185) ============


void FUN_14015ac40(undefined8 param_1,undefined4 *param_2,byte param_3,short param_4,short param_5)



{

  int *piVar1;

  char cVar2;

  undefined4 local_88 [2];

  undefined8 local_80;

  undefined4 local_78;

  byte local_74;

  short local_70;

  short local_6e;

  

  if (((int)(uint)param_3 < (int)param_2[0x14]) && (cVar2 = FUN_14015a640(), cVar2 == '\0')) {

    piVar1 = (int *)(*(longlong *)(param_2 + 0x16) + (ulonglong)param_3 * 8);

    *piVar1 = *piVar1 + (int)param_4;

    piVar1 = (int *)(*(longlong *)(param_2 + 0x16) + 4 + (ulonglong)param_3 * 8);

    *piVar1 = *piVar1 + (int)param_5;

    cVar2 = FUN_140139420(0x601);

    if (cVar2 != '\0') {

      local_78 = *param_2;

      local_88[0] = 0x601;

      local_6e = param_5;

      local_80 = param_1;

      local_74 = param_3;

      local_70 = param_4;

      FUN_14013b140(local_88);

    }

  }

  return;

}




