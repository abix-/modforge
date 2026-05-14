// Address: 0x140157780
// Ghidra name: FUN_140157780
// ============ 0x140157780 FUN_140157780 (size=320) ============


undefined8 *

FUN_140157780(undefined8 *param_1,undefined2 param_2,short param_3,undefined2 param_4,

             undefined2 param_5,char *param_6,char *param_7,char param_8,undefined1 param_9)



{

  undefined2 uVar1;

  size_t sVar2;

  undefined8 uVar3;

  

  uVar1 = 0;

  *param_1 = 0;

  param_1[1] = 0;

  if ((param_6 == (char *)0x0) || (*param_6 == '\0')) {

    if (param_7 == (char *)0x0) goto LAB_14015782e;

LAB_140157819:

    sVar2 = strlen(param_7);

    uVar1 = 0;

  }

  else {

    uVar1 = 0;

    if (param_7 == (char *)0x0) goto LAB_14015782e;

    if (*param_7 == '\0') goto LAB_140157819;

    sVar2 = strlen(param_6);

    uVar1 = FUN_140191680(0,param_6,sVar2);

    uVar1 = FUN_140191680(uVar1,&DAT_14039be68,1);

    sVar2 = strlen(param_7);

  }

  uVar1 = FUN_140191680(uVar1,param_7,sVar2);

LAB_14015782e:

  *(undefined2 *)param_1 = param_2;

  *(undefined2 *)((longlong)param_1 + 2) = uVar1;

  if (param_3 == 0) {

    uVar3 = 0xc;

    if (param_8 != '\0') {

      *(char *)((longlong)param_1 + 0xe) = param_8;

      uVar3 = 10;

      *(undefined1 *)((longlong)param_1 + 0xf) = param_9;

    }

    if (param_7 != (char *)0x0) {

      FUN_14012f1a0((short *)((longlong)param_1 + 4),param_7,uVar3);

    }

  }

  else {

    *(short *)((longlong)param_1 + 4) = param_3;

    *(undefined2 *)((longlong)param_1 + 0xc) = param_5;

    *(undefined2 *)((longlong)param_1 + 6) = 0;

    *(undefined2 *)(param_1 + 1) = param_4;

    *(undefined2 *)((longlong)param_1 + 10) = 0;

    *(char *)((longlong)param_1 + 0xe) = param_8;

    *(undefined1 *)((longlong)param_1 + 0xf) = param_9;

  }

  return param_1;

}




