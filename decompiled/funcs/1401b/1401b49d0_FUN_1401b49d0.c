// Address: 0x1401b49d0
// Ghidra name: FUN_1401b49d0
// ============ 0x1401b49d0 FUN_1401b49d0 (size=277) ============


ulonglong FUN_1401b49d0(longlong param_1,undefined8 param_2,undefined8 param_3)



{

  uint uVar1;

  byte bVar2;

  longlong lVar3;

  ulonglong uVar4;

  uint uVar5;

  uint local_res20 [2];

  uint *puVar6;

  undefined8 local_48 [4];

  

  local_res20[0] = 0;

  puVar6 = local_res20;

  lVar3 = FUN_1401bad30(param_1,param_2,1,local_48,puVar6);

  uVar1 = local_res20[0];

  uVar4 = 0;

  if (local_res20[0] == 0) {

    uVar4 = FUN_1401841e0(lVar3);

    uVar4 = uVar4 & 0xffffffffffffff00;

  }

  else {

    do {

      puVar6 = (uint *)((ulonglong)puVar6 & 0xffffffffffffff00);

      bVar2 = FUN_1401b4af0(param_1,*(undefined4 *)(lVar3 + uVar4 * 4),local_48,local_48[0],puVar6,0

                            ,param_2,param_3);

      if (bVar2 == 1) {

        uVar1 = *(uint *)(lVar3 + uVar4 * 4);

        FUN_1401841e0(lVar3);

        if ((*(char *)(param_1 + 0x579) == '\0') &&

           ((*(byte *)(param_1 + 0x5a4 + (ulonglong)uVar1 * 8) & 1) == 0)) {

          FUN_14012e2e0(9,"Out of device-local memory, allocating textures on host-local memory!");

          *(undefined1 *)(param_1 + 0x579) = 1;

        }

        goto LAB_1401b4a78;

      }

      uVar5 = (int)uVar4 + 1;

      uVar4 = (ulonglong)uVar5;

    } while (uVar5 < uVar1);

    FUN_1401841e0(lVar3);

LAB_1401b4a78:

    uVar4 = (ulonglong)bVar2;

  }

  return uVar4;

}




