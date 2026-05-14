// Address: 0x1402c7e2c
// Ghidra name: FUN_1402c7e2c
// ============ 0x1402c7e2c FUN_1402c7e2c (size=98) ============


undefined8 FUN_1402c7e2c(undefined8 *param_1)



{

  int iVar1;

  int *piVar2;

  undefined8 uVar3;

  undefined8 *puVar4;

  

  piVar2 = (int *)*param_1;

  if ((*piVar2 == -0x1f928c9d) && (piVar2[6] == 4)) {

    iVar1 = piVar2[8];

    if ((iVar1 == 0x19930520) || ((iVar1 + 0xe66cfadfU < 2 || (iVar1 == 0x1994000)))) {

      puVar4 = (undefined8 *)FUN_1402c9134();

      *puVar4 = piVar2;

      uVar3 = param_1[1];

      puVar4 = (undefined8 *)FUN_1402c9148();

      *puVar4 = uVar3;

                    /* WARNING: Subroutine does not return */

      FUN_1402cf8b8();

    }

  }

  return 0;

}




