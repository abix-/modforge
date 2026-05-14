// Address: 0x1402cc18c
// Ghidra name: FUN_1402cc18c
// ============ 0x1402cc18c FUN_1402cc18c (size=149) ============


undefined8 FUN_1402cc18c(undefined8 *param_1,longlong param_2,undefined4 *param_3)



{

  int *piVar1;

  longlong lVar2;

  

  piVar1 = (int *)*param_1;

  *param_3 = 0;

  if (*piVar1 == -0x1f928c9d) {

    if ((piVar1[6] == 4) &&

       (((piVar1[8] == 0x19930520 || (piVar1[8] + 0xe66cfadfU < 2)) &&

        (*(longlong *)(piVar1 + 10) == *(longlong *)(param_2 + 0x28))))) {

      *param_3 = 1;

    }

    if ((((*piVar1 == -0x1f928c9d) && (piVar1[6] == 4)) &&

        ((piVar1[8] == 0x19930520 || (piVar1[8] + 0xe66cfadfU < 2)))) &&

       (*(longlong *)(piVar1 + 0xc) == 0)) {

      lVar2 = FUN_1402c97f8();

      *(undefined4 *)(lVar2 + 0x40) = 1;

      *param_3 = 1;

      return 1;

    }

  }

  return 0;

}




