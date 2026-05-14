// Address: 0x1400259d0
// Ghidra name: FUN_1400259d0
// ============ 0x1400259d0 FUN_1400259d0 (size=493) ============


void FUN_1400259d0(longlong param_1,longlong param_2,uint param_3)



{

  longlong lVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  longlong *plVar4;

  longlong *plVar5;

  

  uVar3 = (ulonglong)param_3;

  if (param_2 == 0) {

    FID_conflict__assert(L"cfile",L"C:\\dev\\tinyxml\\tinyxml.cpp",0x2f7);

  }

  uVar2 = uVar3;

  if (0 < (int)param_3) {

    do {

      FUN_140023ee0(param_2,&DAT_14039bd08);

      uVar2 = uVar2 - 1;

    } while (uVar2 != 0);

  }

  plVar5 = (longlong *)(param_1 + 0x38);

  plVar4 = plVar5;

  if (0xf < *(ulonglong *)(param_1 + 0x50)) {

    plVar4 = (longlong *)*plVar5;

  }

  FUN_140023ee0(param_2,&DAT_14039be64,plVar4);

  plVar4 = *(longlong **)(param_1 + 0xd0);

  if (plVar4 != (longlong *)(param_1 + 0x68)) {

    do {

      if (plVar4 == (longlong *)0x0) break;

      FUN_140023ee0(param_2,&DAT_14039be68);

      (**(code **)(*plVar4 + 8))(plVar4,param_2,param_3);

      plVar4 = (longlong *)plVar4[0xd];

    } while ((plVar4[10] != 0) || (plVar4[6] != 0));

  }

  plVar4 = *(longlong **)(param_1 + 0x28);

  if (plVar4 == (longlong *)0x0) {

    FUN_140023ee0(param_2,&DAT_14039be6c);

  }

  else {

    if ((plVar4 == *(longlong **)(param_1 + 0x30)) &&

       (lVar1 = (**(code **)(*plVar4 + 0x58))(), lVar1 != 0)) {

      FUN_140023ee0(param_2,&DAT_14039be70);

      (**(code **)(**(longlong **)(param_1 + 0x28) + 8))

                (*(longlong **)(param_1 + 0x28),param_2,param_3 + 1);

      if (0xf < *(ulonglong *)(param_1 + 0x50)) {

        plVar5 = (longlong *)*plVar5;

      }

    }

    else {

      FUN_140023ee0(param_2,&DAT_14039be70);

      for (plVar5 = *(longlong **)(param_1 + 0x28); plVar5 != (longlong *)0x0;

          plVar5 = (longlong *)plVar5[0xc]) {

        lVar1 = (**(code **)(*plVar5 + 0x58))(plVar5);

        if (lVar1 == 0) {

          FUN_140023ee0(param_2,&DAT_14039bd10);

        }

        (**(code **)(*plVar5 + 8))(plVar5,param_2,param_3 + 1);

      }

      FUN_140023ee0(param_2,&DAT_14039bd10);

      if (0 < (int)param_3) {

        do {

          FUN_140023ee0(param_2,&DAT_14039bd08);

          uVar3 = uVar3 - 1;

        } while (uVar3 != 0);

      }

      plVar5 = (longlong *)(param_1 + 0x38);

      if (0xf < *(ulonglong *)(param_1 + 0x50)) {

        plVar5 = (longlong *)*plVar5;

      }

    }

    FUN_140023ee0(param_2,"</%s>",plVar5);

  }

  return;

}




