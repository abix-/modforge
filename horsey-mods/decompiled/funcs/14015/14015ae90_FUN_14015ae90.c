// Address: 0x14015ae90
// Ghidra name: FUN_14015ae90
// ============ 0x14015ae90 FUN_14015ae90 (size=171) ============


void FUN_14015ae90(undefined8 param_1,undefined4 *param_2,byte param_3,char param_4)



{

  char cVar1;

  undefined4 local_88 [2];

  undefined8 local_80;

  undefined4 local_78;

  byte local_74;

  char local_73;

  

  if ((((int)(uint)param_3 < (int)param_2[0x18]) &&

      (param_4 != *(char *)((ulonglong)param_3 + *(longlong *)(param_2 + 0x1a)))) &&

     ((cVar1 = FUN_14015a640(), cVar1 == '\0' || (param_4 == '\0')))) {

    *(char *)((ulonglong)param_3 + *(longlong *)(param_2 + 0x1a)) = param_4;

    *(undefined8 *)(param_2 + 0x4e) = param_1;

    cVar1 = FUN_140139420(0x602);

    if (cVar1 != '\0') {

      local_78 = *param_2;

      local_88[0] = 0x602;

      local_80 = param_1;

      local_74 = param_3;

      local_73 = param_4;

      FUN_14013b140(local_88);

    }

  }

  return;

}




