// Address: 0x140266350
// Ghidra name: FUN_140266350
// ============ 0x140266350 FUN_140266350 (size=319) ============


undefined8 FUN_140266350(longlong param_1,undefined8 param_2,byte *param_3,int param_4)



{

  byte bVar1;

  longlong lVar2;

  char cVar3;

  undefined4 uVar4;

  byte bVar5;

  byte bVar6;

  

  uVar4 = 0;

  if (0 < param_4) {

    bVar1 = *param_3;

    bVar6 = bVar1 & 3;

    bVar5 = bVar1 >> 2 & 3;

    if (*(int *)(param_1 + 0xc) != 0) {

      lVar2 = FUN_1401581c0();

      if (lVar2 != 0) {

        cVar3 = '\x01';

        if ((bVar1 & 3) == 0) {

          uVar4 = 1;

        }

        else if (bVar6 == 1) {

          uVar4 = 0x19;

        }

        else if (bVar6 == 2) {

          uVar4 = 0x32;

        }

        else if (bVar6 == 3) {

          uVar4 = 100;

        }

        if ((bVar1 >> 4 & 3) != 0) {

          if ((bVar1 >> 4 & 3) == 1) {

            cVar3 = (bVar6 == 3) + '\x03';

          }

          else {

            cVar3 = '\0';

          }

        }

        if ((bVar1 >> 2 & 3) == 0) {

          cVar3 = '\x02';

        }

        else if ((bVar5 != 1) && (bVar5 != 2)) {

          cVar3 = '\0';

        }

        FUN_14015af40(lVar2,cVar3,uVar4);

      }

    }

    if ((param_4 < 4) || ((param_3[1] & 2) == 0)) {

LAB_140266476:

      FUN_140265350(param_1);

      return 1;

    }

    if (4 < param_4) {

      bVar1 = param_3[4];

      if (bVar1 < 6) {

        if ((int)(((uint)bVar1 + (uint)bVar1 * 4) * 2 + 5) <= param_4) goto LAB_140266476;

      }

      else {

        FUN_14012e2e0(7,"GIP: Device reported too many events, %d > 5",bVar1);

      }

    }

  }

  return 0;

}




