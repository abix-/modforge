// Address: 0x1400cd0f0
// Ghidra name: FUN_1400cd0f0
// ============ 0x1400cd0f0 FUN_1400cd0f0 (size=472) ============


void FUN_1400cd0f0(longlong param_1)



{

  longlong *plVar1;

  undefined4 uVar2;

  char cVar3;

  longlong lVar4;

  longlong lVar5;

  uint uVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  

  uVar2 = DAT_140303354;

  lVar5 = *(longlong *)(param_1 + 0xb8);

  uVar8 = 0;

  lVar4 = *(longlong *)(param_1 + 0xc0) - lVar5 >> 3;

  if (*(float *)(param_1 + 0x238) <= 0.0) {

    uVar7 = uVar8;

    if (lVar4 != 0) {

      do {

        plVar1 = *(longlong **)(uVar8 + lVar5);

        if (((int)plVar1[1] == 3) && ((int)uVar7 != *(int *)(param_1 + 0xd4))) {

          (**(code **)(*plVar1 + 0x30))(plVar1,uVar2);

        }

        lVar5 = *(longlong *)(param_1 + 0xb8);

        uVar6 = (int)uVar7 + 1;

        uVar8 = uVar8 + 8;

        uVar7 = (ulonglong)uVar6;

      } while ((ulonglong)(longlong)(int)uVar6 <

               (ulonglong)(*(longlong *)(param_1 + 0xc0) - lVar5 >> 3));

    }

  }

  else {

    uVar7 = uVar8;

    uVar9 = uVar8;

    if (lVar4 != 0) {

      do {

        plVar1 = *(longlong **)(uVar9 + lVar5);

        if ((((int)plVar1[1] == 3) && ((int)uVar7 != *(int *)(param_1 + 0xd4))) &&

           (cVar3 = FUN_1400c56f0((int)plVar1[5],*(undefined4 *)((longlong)plVar1 + 0x2c),

                                  *(undefined8 *)(param_1 + 0x78),0), cVar3 == '\0')) {

          (**(code **)(*plVar1 + 0x30))(plVar1,uVar2);

        }

        lVar5 = *(longlong *)(param_1 + 0xb8);

        uVar6 = (int)uVar7 + 1;

        uVar7 = (ulonglong)uVar6;

        uVar9 = uVar9 + 8;

      } while ((ulonglong)(longlong)(int)uVar6 <

               (ulonglong)(*(longlong *)(param_1 + 0xc0) - lVar5 >> 3));

    }

    FUN_140072f50(*(undefined4 *)(param_1 + 0x238),0);

    lVar5 = *(longlong *)(param_1 + 0xb8);

    uVar7 = uVar8;

    if (*(longlong *)(param_1 + 0xc0) - lVar5 >> 3 != 0) {

      do {

        plVar1 = *(longlong **)(uVar7 + lVar5);

        if ((((int)plVar1[1] == 3) && ((int)uVar8 != *(int *)(param_1 + 0xd4))) &&

           (cVar3 = FUN_1400c56f0((int)plVar1[5],*(undefined4 *)((longlong)plVar1 + 0x2c),

                                  *(undefined8 *)(param_1 + 0x78),0), cVar3 != '\0')) {

          (**(code **)(*plVar1 + 0x30))(plVar1,uVar2);

        }

        lVar5 = *(longlong *)(param_1 + 0xb8);

        uVar6 = (int)uVar8 + 1;

        uVar8 = (ulonglong)uVar6;

        uVar7 = uVar7 + 8;

      } while ((ulonglong)(longlong)(int)uVar6 <

               (ulonglong)(*(longlong *)(param_1 + 0xc0) - lVar5 >> 3));

    }

    FUN_1400730f0();

  }

  return;

}




