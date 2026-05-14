// Address: 0x14019ec00
// Ghidra name: FUN_14019ec00
// ============ 0x14019ec00 FUN_14019ec00 (size=326) ============


ulonglong FUN_14019ec00(longlong *param_1,int param_2)



{

  longlong lVar1;

  char cVar2;

  byte bVar3;

  int iVar4;

  ulonglong uVar5;

  uint uVar6;

  

  *(undefined4 *)((longlong)param_1 + 0x484c) = 0xffffffff;

  *(undefined4 *)(param_1 + 0x909) = 0;

  *(undefined1 *)(param_1 + 0x905) = 0xff;

  cVar2 = FUN_14019f370();

  if (cVar2 != -0x28) {

    uVar5 = FUN_14019f050("Corrupt JPEG");

    return uVar5;

  }

  if (param_2 == 1) {

    return 1;

  }

  bVar3 = FUN_14019f370(param_1);

  uVar6 = (uint)bVar3;

  if (bVar3 != 0xc0) {

    do {

      if (uVar6 - 0xc1 < 2) break;

      iVar4 = FUN_1401a3830(param_1);

      if (iVar4 == 0) {

        return 0;

      }

      bVar3 = FUN_14019f370(param_1);

      while (bVar3 == 0xff) {

        lVar1 = *param_1;

        if (*(longlong *)(lVar1 + 0x10) == 0) {

LAB_14019ecbc:

          if (*(ulonglong *)(lVar1 + 200) <= *(ulonglong *)(lVar1 + 0xc0)) {

LAB_14019ed1f:

            uVar5 = FUN_14019f050("Corrupt JPEG");

            return uVar5;

          }

        }

        else {

          iVar4 = (**(code **)(lVar1 + 0x20))(*(undefined8 *)(lVar1 + 0x28));

          if (iVar4 != 0) {

            if (*(int *)(lVar1 + 0x30) == 0) goto LAB_14019ed1f;

            goto LAB_14019ecbc;

          }

        }

        bVar3 = FUN_14019f370(param_1);

      }

      uVar6 = (uint)bVar3;

    } while (uVar6 != 0xc0);

  }

  *(uint *)(param_1 + 0x906) = (uint)(uVar6 == 0xc2);

  iVar4 = FUN_1401a32d0(param_1,param_2);

  return (ulonglong)(iVar4 != 0);

}




