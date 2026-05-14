// Address: 0x1401041f0
// Ghidra name: FUN_1401041f0
// ============ 0x1401041f0 FUN_1401041f0 (size=365) ============


void FUN_1401041f0(longlong param_1)



{

  longlong *plVar1;

  int *piVar2;

  longlong *plVar3;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  undefined8 local_10;

  

  *(undefined4 *)(param_1 + 0x25c) = 0xffffffff;

  *(undefined4 *)(param_1 + 600) = 0;

  *(undefined4 *)(param_1 + 0x36c) = 0;

  *(undefined4 *)(param_1 + 0x3c4) = 0;

  *(undefined4 *)(param_1 + 0x1f8) = 0;

  *(undefined8 *)(param_1 + 0x3a8) = 0;

  *(undefined4 *)(param_1 + 900) = 0;

  *(undefined4 *)(param_1 + 0xd0) = 0xffffffff;

  FUN_140104370();

  FUN_1400a89f0(*(undefined8 *)(param_1 + 0x300));

  if ((DAT_1403d9524 != '\0') && (*(int *)(param_1 + 0x254) != 0)) {

    FUN_14006dc80(param_1,1);

  }

  if ((DAT_1403d9529 != '\0') && (*(int *)(param_1 + 0x254) != 0)) {

    *(undefined1 *)(DAT_1403ee020 + 0x2a) = 1;

  }

  local_18 = 5;

  uStack_20 = 0;

  local_10 = 0xf;

  local_28 = (ulonglong)CONCAT14(s_World_14030a640[4],s_World_14030a640._0_4_);

  FUN_14003f590(&local_28);

  piVar2 = (int *)&DAT_1403d9530;

  if (0xf < DAT_1403d9548) {

    piVar2 = DAT_1403d9530;

  }

  if ((DAT_1403d9540 == 4) && (*piVar2 == 0x706d7550)) {

    FUN_140105260(param_1);

  }

  DAT_1403ed968 = 1;

  FUN_140107660(param_1);

  if (DAT_1403f4bb1 == '\0') {

    plVar1 = *(longlong **)(DAT_1403f4e00 + 0x138);

    for (plVar3 = *(longlong **)(DAT_1403f4e00 + 0x130); plVar3 != plVar1; plVar3 = plVar3 + 1) {

      if (*(char *)(*plVar3 + 0x206) != '\0') {

        *(undefined4 *)(DAT_1403fb0d8 + 0x440) = 0;

      }

    }

  }

  return;

}




