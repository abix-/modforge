// Address: 0x1402c55b0
// Ghidra name: FUN_1402c55b0
// ============ 0x1402c55b0 FUN_1402c55b0 (size=248) ============


undefined8 FUN_1402c55b0(undefined8 *param_1,byte *param_2,int param_3)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  char cVar4;

  undefined8 uVar5;

  byte *pbVar6;

  byte *pbVar7;

  longlong lVar8;

  

  *param_1 = 0;

  param_1[1] = 0;

  pbVar7 = param_2 + param_3;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[8] = 0;

  do {

    while( true ) {

      if (pbVar7 <= param_2) {

        return 1;

      }

      bVar1 = *param_2;

      pbVar6 = param_2 + 1;

      bVar2 = bVar1 >> 4;

      lVar8 = (longlong)*(int *)(&DAT_140383a90 + (ulonglong)(bVar1 & 3) * 4);

      param_2 = pbVar6 + lVar8;

      if (pbVar7 < param_2) {

        uVar5 = FUN_14012e850("Invalid descriptor");

        return uVar5;

      }

      bVar3 = bVar1 >> 2 & 3;

      if ((bVar1 >> 2 & 3) != 0) break;

      cVar4 = FUN_1402c5810(param_1,bVar2,lVar8,pbVar6);

LAB_1402c5672:

      if (cVar4 == '\0') {

        return 0;

      }

    }

    if (bVar3 == 1) {

      cVar4 = FUN_1402c56b0(param_1,bVar2,lVar8,pbVar6);

      goto LAB_1402c5672;

    }

    if (bVar3 == 2) {

      cVar4 = FUN_1402c5770(param_1,bVar2,lVar8,pbVar6);

      goto LAB_1402c5672;

    }

    if (bVar3 == 3) {

      uVar5 = FUN_14012e850("That operation is not supported");

      return uVar5;

    }

  } while( true );

}




