// Address: 0x140026b90
// Ghidra name: FUN_140026b90
// ============ 0x140026b90 FUN_140026b90 (size=1125) ============


void FUN_140026b90(longlong param_1,longlong param_2,undefined8 param_3,undefined8 *param_4)



{

  ulonglong uVar1;

  undefined8 *puVar2;

  longlong lVar3;

  longlong *plVar4;

  

  if (param_2 != 0) {

    FUN_140023ee0(param_2,"<?xml ");

  }

  if (param_4 != (undefined8 *)0x0) {

    uVar1 = param_4[3];

    lVar3 = param_4[2];

    if (uVar1 - lVar3 < 6) {

      FUN_140027c80(param_4,6,uVar1,"<?xml ",6);

    }

    else {

      param_4[2] = lVar3 + 6;

      puVar2 = param_4;

      if (0xf < uVar1) {

        puVar2 = (undefined8 *)*param_4;

      }

      FUN_1402f8e20((longlong)puVar2 + lVar3,"<?xml ",6);

      *(undefined1 *)((longlong)puVar2 + lVar3 + 6) = 0;

    }

  }

  if (*(longlong *)(param_1 + 0x78) != 0) {

    if (param_2 != 0) {

      plVar4 = (longlong *)(param_1 + 0x68);

      if (0xf < *(ulonglong *)(param_1 + 0x80)) {

        plVar4 = (longlong *)*plVar4;

      }

      FUN_140023ee0(param_2,"version=\"%s\" ",plVar4);

    }

    if (param_4 != (undefined8 *)0x0) {

      lVar3 = param_4[2];

      if ((ulonglong)(param_4[3] - lVar3) < 9) {

        FUN_140027c80(param_4,9);

      }

      else {

        param_4[2] = lVar3 + 9;

        puVar2 = param_4;

        if (0xf < (ulonglong)param_4[3]) {

          puVar2 = (undefined8 *)*param_4;

        }

        FUN_1402f8e20((longlong)puVar2 + lVar3,"version=\"",9);

        *(undefined1 *)((longlong)puVar2 + lVar3 + 9) = 0;

      }

      lVar3 = param_1 + 0x68;

      if (0xf < *(ulonglong *)(param_1 + 0x80)) {

        lVar3 = *(longlong *)(param_1 + 0x68);

      }

      FUN_140027810(param_4,lVar3,*(undefined8 *)(param_1 + 0x78));

      lVar3 = param_4[2];

      if ((ulonglong)(param_4[3] - lVar3) < 2) {

        FUN_140027c80(param_4,2);

      }

      else {

        param_4[2] = lVar3 + 2;

        puVar2 = param_4;

        if (0xf < (ulonglong)param_4[3]) {

          puVar2 = (undefined8 *)*param_4;

        }

        *(undefined2 *)((longlong)puVar2 + lVar3) = 0x2022;

        *(undefined1 *)((longlong)puVar2 + lVar3 + 2) = 0;

      }

    }

  }

  if (*(longlong *)(param_1 + 0x98) != 0) {

    if (param_2 != 0) {

      plVar4 = (longlong *)(param_1 + 0x88);

      if (0xf < *(ulonglong *)(param_1 + 0xa0)) {

        plVar4 = (longlong *)*plVar4;

      }

      FUN_140023ee0(param_2,"encoding=\"%s\" ",plVar4);

    }

    if (param_4 != (undefined8 *)0x0) {

      lVar3 = param_4[2];

      if ((ulonglong)(param_4[3] - lVar3) < 10) {

        FUN_140027c80(param_4,10);

      }

      else {

        param_4[2] = lVar3 + 10;

        puVar2 = param_4;

        if (0xf < (ulonglong)param_4[3]) {

          puVar2 = (undefined8 *)*param_4;

        }

        FUN_1402f8e20((longlong)puVar2 + lVar3,"encoding=\"",10);

        *(undefined1 *)((longlong)puVar2 + lVar3 + 10) = 0;

      }

      lVar3 = param_1 + 0x88;

      if (0xf < *(ulonglong *)(param_1 + 0xa0)) {

        lVar3 = *(longlong *)(param_1 + 0x88);

      }

      FUN_140027810(param_4,lVar3,*(undefined8 *)(param_1 + 0x98));

      lVar3 = param_4[2];

      if ((ulonglong)(param_4[3] - lVar3) < 2) {

        FUN_140027c80(param_4,2);

      }

      else {

        param_4[2] = lVar3 + 2;

        puVar2 = param_4;

        if (0xf < (ulonglong)param_4[3]) {

          puVar2 = (undefined8 *)*param_4;

        }

        *(undefined2 *)((longlong)puVar2 + lVar3) = 0x2022;

        *(undefined1 *)((longlong)puVar2 + lVar3 + 2) = 0;

      }

    }

  }

  if (*(longlong *)(param_1 + 0xb8) != 0) {

    if (param_2 != 0) {

      plVar4 = (longlong *)(param_1 + 0xa8);

      if (0xf < *(ulonglong *)(param_1 + 0xc0)) {

        plVar4 = (longlong *)*plVar4;

      }

      FUN_140023ee0(param_2,"standalone=\"%s\" ",plVar4);

    }

    if (param_4 != (undefined8 *)0x0) {

      lVar3 = param_4[2];

      if ((ulonglong)(param_4[3] - lVar3) < 0xc) {

        FUN_140027c80(param_4,0xc);

      }

      else {

        param_4[2] = lVar3 + 0xc;

        puVar2 = param_4;

        if (0xf < (ulonglong)param_4[3]) {

          puVar2 = (undefined8 *)*param_4;

        }

        FUN_1402f8e20((longlong)puVar2 + lVar3,"standalone=\"",0xc);

        *(undefined1 *)((longlong)puVar2 + lVar3 + 0xc) = 0;

      }

      lVar3 = param_1 + 0xa8;

      if (0xf < *(ulonglong *)(param_1 + 0xc0)) {

        lVar3 = *(longlong *)(param_1 + 0xa8);

      }

      FUN_140027810(param_4,lVar3,*(undefined8 *)(param_1 + 0xb8));

      lVar3 = param_4[2];

      if ((ulonglong)(param_4[3] - lVar3) < 2) {

        FUN_140027c80(param_4,2);

      }

      else {

        param_4[2] = lVar3 + 2;

        puVar2 = param_4;

        if (0xf < (ulonglong)param_4[3]) {

          puVar2 = (undefined8 *)*param_4;

        }

        *(undefined2 *)((longlong)puVar2 + lVar3) = 0x2022;

        *(undefined1 *)((longlong)puVar2 + lVar3 + 2) = 0;

      }

    }

  }

  if (param_2 != 0) {

    FUN_140023ee0(param_2,&DAT_14039bfa8);

  }

  if (param_4 != (undefined8 *)0x0) {

    lVar3 = param_4[2];

    if (1 < (ulonglong)(param_4[3] - lVar3)) {

      param_4[2] = lVar3 + 2;

      if (0xf < (ulonglong)param_4[3]) {

        param_4 = (undefined8 *)*param_4;

      }

      *(undefined2 *)((longlong)param_4 + lVar3) = 0x3e3f;

      *(undefined1 *)((longlong)param_4 + lVar3 + 2) = 0;

      return;

    }

    FUN_140027c80(param_4,2);

  }

  return;

}




