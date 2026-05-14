// Address: 0x1401560b0
// Ghidra name: FUN_1401560b0
// ============ 0x1401560b0 FUN_1401560b0 (size=410) ============


ulonglong FUN_1401560b0(longlong param_1)



{

  uint *puVar1;

  byte bVar2;

  ulonglong uVar3;

  longlong lVar4;

  uint uVar5;

  undefined4 local_res8 [2];

  undefined8 local_38;

  undefined8 local_30;

  int local_28;

  int local_24;

  

  puVar1 = *(uint **)(param_1 + 0xf8);

  bVar2 = 1;

  uVar3 = FUN_140205fa0(*(undefined8 *)(param_1 + 0x100));

  if ((char)uVar3 != '\0') {

    local_24 = *(int *)(param_1 + 8);

    local_28 = *(int *)(param_1 + 4);

    local_30 = 0;

    if (*(int *)(param_1 + 0x24) != 1) {

      uVar5 = *puVar1;

      if ((uVar5 == 0) || ((uVar5 & 0xf0000000) == 0x10000000)) {

        uVar5 = uVar5 & 0xff;

      }

      else if ((((uVar5 == 0x32595559) || (uVar5 == 0x59565955)) || (uVar5 == 0x55595659)) ||

              (uVar5 == 0x30313050)) {

        uVar5 = 2;

      }

      else {

        uVar5 = 1;

      }

      uVar5 = uVar5 * local_28 + 3 & 0xfffffffc;

      if ((longlong)(int)uVar5 * (longlong)local_24 != 0) {

        lVar4 = FUN_1401841f0();

        uVar3 = 0;

        if (lVar4 == 0) goto LAB_140156233;

        bVar2 = FUN_140205a00(*(undefined8 *)(param_1 + 0x100),&local_30,*puVar1,local_28,local_24,

                              lVar4,uVar5);

        if (bVar2 != 0) {

          FUN_140156430(puVar1,&local_30,lVar4,uVar5);

        }

        FUN_1401841e0(lVar4);

      }

      return (ulonglong)bVar2;

    }

    local_38 = 0;

    local_res8[0] = 0;

    uVar3 = FUN_14014f910(puVar1,&local_30,&local_38,local_res8);

    if ((char)uVar3 != '\0') {

      bVar2 = FUN_140205a00(*(undefined8 *)(param_1 + 0x100),&local_30,*puVar1,local_28,local_24,

                            local_38,local_res8[0]);

      FUN_1401556c0(puVar1);

      return (ulonglong)bVar2;

    }

  }

LAB_140156233:

  return uVar3 & 0xffffffffffffff00;

}




