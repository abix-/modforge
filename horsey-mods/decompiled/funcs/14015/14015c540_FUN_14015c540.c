// Address: 0x14015c540
// Ghidra name: FUN_14015c540
// ============ 0x14015c540 FUN_14015c540 (size=86) ============


undefined8 FUN_14015c540(int *param_1,undefined8 param_2,undefined4 param_3,longlong param_4)



{

  char cVar1;

  int iVar2;

  

  cVar1 = FUN_14015ec30(param_3);

  if (cVar1 == (char)param_1[6]) {

    iVar2 = FUN_140138fe0(param_4 + 0x90);

    if (iVar2 != 0) {

      param_1[1] = param_1[1] + 1;

      return 1;

    }

    *(undefined4 *)(*(longlong *)(param_1 + 4) + (longlong)*param_1 * 4) = param_3;

    *param_1 = *param_1 + 1;

  }

  return 1;

}




