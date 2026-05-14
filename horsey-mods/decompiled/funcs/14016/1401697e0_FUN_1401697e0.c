// Address: 0x1401697e0
// Ghidra name: FUN_1401697e0
// ============ 0x1401697e0 FUN_1401697e0 (size=472) ============


undefined8

FUN_1401697e0(longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4,

             ulonglong param_5)



{

  int *piVar1;

  char cVar2;

  longlong lVar3;

  undefined8 uVar4;

  longlong lVar5;

  longlong lVar6;

  char *pcVar7;

  ulonglong uVar8;

  longlong local_28 [2];

  

  lVar3 = FUN_14016dcf0();

  if (lVar3 == 0) {

    uVar4 = FUN_1401730c0();

    return uVar4;

  }

  if (param_1 == 0) {

    if ((param_4 == 0) && (param_5 == 0)) goto LAB_140169860;

  }

  else if ((param_4 != 0) && (param_5 != 0)) {

LAB_140169860:

    FUN_140168fa0(0);

    piVar1 = (int *)(lVar3 + 0x358);

    *piVar1 = *piVar1 + 1;

    if (*piVar1 == 0) {

      *(undefined4 *)(lVar3 + 0x358) = 1;

    }

    *(longlong *)(lVar3 + 0x360) = param_1;

    *(undefined8 *)(lVar3 + 0x368) = param_2;

    *(undefined8 *)(lVar3 + 0x370) = param_3;

    cVar2 = FUN_140169700(param_4,param_5);

    if (cVar2 == '\0') {

      FUN_140169010();

      return 0;

    }

    if (*(code **)(lVar3 + 0x2a8) == (code *)0x0) {

      if (*(longlong *)(lVar3 + 0x2c0) != 0) {

        uVar8 = 0;

        if (param_5 != 0) {

          do {

            uVar4 = *(undefined8 *)(*(longlong *)(lVar3 + 0x378) + uVar8 * 8);

            cVar2 = FUN_1401696e0(uVar4);

            if ((cVar2 != '\0') &&

               (lVar5 = (**(code **)(lVar3 + 0x360))(*(undefined8 *)(lVar3 + 0x370),uVar4,local_28),

               lVar5 != 0)) {

              lVar6 = FUN_1401841f0(local_28[0] + 1);

              FUN_1402f8e20(lVar6,lVar5,local_28[0]);

              *(undefined1 *)(local_28[0] + lVar6) = 0;

              cVar2 = (**(code **)(lVar3 + 0x2c0))(lVar3,lVar6);

              if (cVar2 == '\0') {

                FUN_1401841e0(lVar6);

                return 0;

              }

              if (lVar6 != 0) {

                FUN_1401841e0(lVar6);

                goto LAB_140169926;

              }

              break;

            }

            uVar8 = uVar8 + 1;

          } while (uVar8 < param_5);

        }

        cVar2 = (**(code **)(lVar3 + 0x2c0))(lVar3,&DAT_14039bcb9);

        goto LAB_140169922;

      }

    }

    else {

      cVar2 = (**(code **)(lVar3 + 0x2a8))(lVar3);

LAB_140169922:

      if (cVar2 == '\0') {

        return 0;

      }

    }

LAB_140169926:

    lVar3 = FUN_140169080(param_4,param_5,1);

    if (lVar3 != 0) {

      FUN_140218400(1,lVar3,param_5);

      return 1;

    }

    pcVar7 = "unable to copy current mime types";

    goto LAB_140169833;

  }

  pcVar7 = "Invalid parameters";

LAB_140169833:

  uVar4 = FUN_14012e850(pcVar7);

  return uVar4;

}




