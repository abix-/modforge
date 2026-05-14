// Address: 0x1402d7740
// Ghidra name: FUN_1402d7740
// ============ 0x1402d7740 FUN_1402d7740 (size=207) ============


void FUN_1402d7740(longlong *param_1,char *param_2,int param_3,int *param_4,longlong param_5)



{

  undefined8 uVar1;

  int iVar2;

  char *pcVar3;

  

  pcVar3 = param_2 + param_3;

  uVar1 = *(undefined8 *)(param_5 + 0x2c);

  do {

    if (param_2 == pcVar3) {

LAB_1402d77f2:

      *(undefined8 *)(param_5 + 0x2c) = uVar1;

      return;

    }

    if ((((*(uint *)(*param_1 + 0x14) >> 0xc & 1) == 0) || (*(longlong *)(*param_1 + 8) != 0)) &&

       (iVar2 = FUN_1402db090((int)*param_2,*param_1,param_5), iVar2 == -1)) {

      if ((*(char *)(param_5 + 0x30) == '\0') || (*(int *)(param_5 + 0x2c) != 0x2a)) {

        *param_4 = -1;

        goto LAB_1402d77f2;

      }

      if ((((*(uint *)(*param_1 + 0x14) >> 0xc & 1) != 0) && (*(longlong *)(*param_1 + 8) == 0)) ||

         (iVar2 = FUN_1402db090(0x3f,*param_1,param_5), iVar2 != -1)) goto LAB_1402d77de;

      *param_4 = -1;

    }

    else {

LAB_1402d77de:

      *param_4 = *param_4 + 1;

    }

    param_2 = param_2 + 1;

  } while( true );

}




