// Address: 0x140280e70
// Ghidra name: FUN_140280e70
// ============ 0x140280e70 FUN_140280e70 (size=187) ============


undefined4 FUN_140280e70(longlong param_1,char param_2,char *param_3,undefined8 param_4)



{

  int iVar1;

  int iVar2;

  

  iVar2 = 0;

  do {

    FUN_1401492f0(1);

    iVar1 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),param_3,param_4,0);

    if (iVar1 < 0) {

      return 0;

    }

    if ((iVar1 != 0) && (iVar1 == 0x20)) {

      if ((param_3[1] == 'Z') && (param_3[2] == -0x5b)) {

        FUN_1402f8e20(param_3,param_3 + 1,0x1f);

        param_3[0x1f] = '\0';

      }

      if (((*param_3 == 'Z') && (param_3[1] == -0x5b)) && (param_3[2] == param_2)) {

        return 1;

      }

    }

    iVar2 = iVar2 + 1;

    if (99 < iVar2) {

      return 0;

    }

  } while( true );

}




