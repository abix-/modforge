// Address: 0x1402d7810
// Ghidra name: FUN_1402d7810
// ============ 0x1402d7810 FUN_1402d7810 (size=225) ============


void FUN_1402d7810(longlong *param_1,undefined2 *param_2,int param_3,int *param_4,longlong param_5)



{

  undefined2 *puVar1;

  undefined8 uVar2;

  short sVar3;

  

  uVar2 = *(undefined8 *)(param_5 + 0x2c);

  puVar1 = param_2 + param_3;

  do {

    if (param_2 == puVar1) {

LAB_1402d78d4:

      *(undefined8 *)(param_5 + 0x2c) = uVar2;

      return;

    }

    if ((((*(uint *)(*param_1 + 0x14) >> 0xc & 1) == 0) || (*(longlong *)(*param_1 + 8) != 0)) &&

       (sVar3 = FUN_1402f0614(*param_2,*param_1,param_5), sVar3 == -1)) {

      if ((*(char *)(param_5 + 0x30) == '\0') || (*(int *)(param_5 + 0x2c) != 0x2a)) {

        *param_4 = -1;

        goto LAB_1402d78d4;

      }

      if ((((*(uint *)(*param_1 + 0x14) >> 0xc & 1) != 0) && (*(longlong *)(*param_1 + 8) == 0)) ||

         (sVar3 = FUN_1402f0614(0x3f,*param_1,param_5), sVar3 != -1)) goto LAB_1402d78bb;

      *param_4 = -1;

    }

    else {

LAB_1402d78bb:

      *param_4 = *param_4 + 1;

    }

    param_2 = param_2 + 1;

  } while( true );

}




