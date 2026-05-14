// Address: 0x140268cd0
// Ghidra name: FUN_140268cd0
// ============ 0x140268cd0 FUN_140268cd0 (size=525) ============


byte FUN_140268cd0(longlong param_1)



{

  longlong *plVar1;

  longlong lVar2;

  char cVar3;

  int iVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  uint uVar8;

  

  plVar1 = *(longlong **)(param_1 + 0x70);

  uVar7 = 0;

  uVar8 = 0;

  uVar5 = FUN_140149350();

  uVar6 = uVar7;

  if (0 < *(int *)(param_1 + 0x8c)) {

    uVar6 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));

  }

  iVar4 = FUN_14026c790(plVar1);

  while (0 < iVar4) {

    uVar8 = (int)uVar7 + 1;

    uVar7 = (ulonglong)uVar8;

    plVar1[0x14] = uVar5;

    if (uVar6 != 0) {

      if ((char)plVar1[2] == '\0') {

        cVar3 = (char)plVar1[8];

        if (cVar3 != '!') {

          *(char *)((longlong)plVar1 + 0x25) = cVar3;

          if ((cVar3 == '0') || (cVar3 == '1')) {

            FUN_14026d2a0(plVar1);

            FUN_14026a530(uVar6,plVar1,(longlong)plVar1 + 0x41);

          }

          else if (cVar3 == '?') {

            FUN_14026bb40(uVar6,plVar1,(longlong)plVar1 + 0x41);

          }

        }

      }

      else {

        FUN_14026add0(uVar6,plVar1,plVar1 + 8);

      }

    }

    iVar4 = FUN_14026c790(plVar1);

  }

  if (uVar6 == 0) goto LAB_140268e66;

  if (uVar8 == 0) {

    if ((char)plVar1[2] == '\0') {

      if (*(char *)(param_1 + 0x54) == '\0') {

        if (*(short *)(*plVar1 + 0x22) != 0x200e) {

          if (plVar1[0x14] + 100U <= uVar5) {

            lVar2 = plVar1[3];

            *(undefined1 *)(plVar1 + 3) = 1;

            FUN_14026d490(plVar1,4,0,0,0);

            *(char *)(plVar1 + 3) = (char)lVar2;

          }

          goto LAB_140268e29;

        }

        goto LAB_140268e05;

      }

    }

    else {

LAB_140268e05:

      if (*(char *)(param_1 + 0x54) == '\0') goto LAB_140268e29;

    }

    if ((*(char *)((longlong)plVar1 + 0x25) != '?') && (plVar1[0x14] + 3000U <= uVar5)) {

      iVar4 = -1;

    }

  }

LAB_140268e29:

  if (((char)plVar1[0x12] == '\0') && (*(char *)((longlong)plVar1 + 0x91) == '\0')) {

    if (((char)plVar1[0x10] != '\0') && (plVar1[0x11] + 0x32U <= uVar5)) {

      FUN_14026d560(plVar1);

    }

  }

  else {

    FUN_140269ba0(plVar1);

  }

LAB_140268e66:

  if ((((*(int *)(param_1 + 0x8c) == 0) && (*(char *)(param_1 + 0x54) != '\0')) && (0 < (int)uVar8))

     && ((*(longlong *)(param_1 + 0xa0) == 0 &&

         (cVar3 = FUN_140207f20(*(undefined8 *)(param_1 + 0x28)), cVar3 == '\0')))) {

    FUN_140208110(param_1,0);

  }

  if ((iVar4 < 0) && (0 < *(int *)(param_1 + 0x8c))) {

    FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));

  }

  return (byte)((uint)iVar4 >> 0x1f) ^ 1;

}




