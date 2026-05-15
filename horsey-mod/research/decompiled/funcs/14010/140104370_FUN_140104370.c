// Address: 0x140104370
// Ghidra name: FUN_140104370
// ============ 0x140104370 FUN_140104370 (size=650) ============


void FUN_140104370(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  longlong lVar3;

  int iVar4;

  ulonglong uVar5;

  uint uVar6;

  ulonglong uVar7;

  

  uVar7 = 0;

  *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x39d) =

       *(undefined1 *)(*(longlong *)(param_1 + 0x300) + 0xad);

  *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x405) =

       *(undefined1 *)(*(longlong *)(param_1 + 0x300) + 0xad);

  *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x46d) =

       *(undefined1 *)(*(longlong *)(param_1 + 0x300) + 0xad);

  *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x4d5) =

       *(undefined1 *)(*(longlong *)(param_1 + 0x300) + 0xad);

  *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x53d) =

       *(undefined1 *)(*(longlong *)(param_1 + 0x300) + 0xad);

  uVar5 = uVar7;

  if ((*(char *)(param_1 + 0x321) != '\0') &&

     (uVar5 = 0, *(char *)(*(longlong *)(param_1 + 0x300) + 0xad) == '\0')) {

    uVar5 = 1;

    *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x5a5) = 1;

    *(undefined4 *)(*(longlong *)(param_1 + 0x60) + 0x59c) = 0;

  }

  if ((*(char *)(param_1 + 0x329) != '\0') &&

     (*(char *)(*(longlong *)(param_1 + 0x300) + 0xad) == '\0')) {

    lVar2 = (uVar5 + 0xd) * 0x68;

    uVar5 = (ulonglong)((int)uVar5 + 1);

    *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x5d + lVar2) = 1;

    *(undefined4 *)(*(longlong *)(param_1 + 0x60) + 0x54 + lVar2) = 1;

  }

  if ((*(char *)(param_1 + 0x331) != '\0') &&

     (*(char *)(*(longlong *)(param_1 + 0x300) + 0xad) == '\0')) {

    lVar2 = (uVar5 + 0xd) * 0x68;

    uVar5 = (ulonglong)((int)uVar5 + 1);

    *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x5d + lVar2) = 1;

    *(undefined4 *)(*(longlong *)(param_1 + 0x60) + 0x54 + lVar2) = 2;

  }

  if ((*(char *)(param_1 + 0x339) != '\0') &&

     (*(char *)(*(longlong *)(param_1 + 0x300) + 0xad) == '\0')) {

    lVar2 = (uVar5 + 0xd) * 0x68;

    uVar5 = (ulonglong)((int)uVar5 + 1);

    *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x5d + lVar2) = 1;

    *(undefined4 *)(*(longlong *)(param_1 + 0x60) + 0x54 + lVar2) = 3;

  }

  if (*(char *)(param_1 + 0x341) != '\0') {

    lVar2 = (uVar5 + 0xd) * 0x68;

    uVar5 = (ulonglong)((int)uVar5 + 1);

    *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x5d + lVar2) = 1;

    *(undefined4 *)(*(longlong *)(param_1 + 0x60) + 0x54 + lVar2) = 4;

  }

  iVar4 = (int)uVar5;

  if ((*(char *)(param_1 + 0x349) != '\0') &&

     (*(char *)(*(longlong *)(param_1 + 0x300) + 0xac) == '\0')) {

    lVar2 = (uVar5 + 0xd) * 0x68;

    iVar4 = iVar4 + 1;

    *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x5d + lVar2) = 1;

    *(undefined4 *)(*(longlong *)(param_1 + 0x60) + 0x54 + lVar2) = 5;

  }

  if ((ulonglong)(longlong)iVar4 < 6) {

    lVar2 = (longlong)iVar4 * 0x68;

    do {

      *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x5a5 + lVar2) = 0;

      lVar2 = lVar2 + 0x68;

    } while (lVar2 < 0x270);

  }

  if ((*(int *)(param_1 + 0x34c) != -1) &&

     (*(char *)((longlong)*(int *)(param_1 + 0x34c) * 0x68 + 0x5a5 + *(longlong *)(param_1 + 0x60))

      == '\0')) {

    *(undefined4 *)(param_1 + 0x34c) = 0xffffffff;

  }

  lVar2 = *(longlong *)(param_1 + 0x60);

  lVar3 = *(longlong *)(param_1 + 0x68) - lVar2;

  lVar1 = lVar3 >> 0x3f;

  uVar5 = uVar7;

  if (lVar3 / 0x68 + lVar1 != lVar1) {

    do {

      uVar6 = (int)uVar7 + 1;

      uVar7 = (ulonglong)uVar6;

      *(undefined1 *)(lVar2 + 0x5e + uVar5) = *(undefined1 *)(lVar2 + 0x5d + uVar5);

      lVar2 = *(longlong *)(param_1 + 0x60);

      uVar5 = uVar5 + 0x68;

    } while ((ulonglong)(longlong)(int)uVar6 <

             (ulonglong)((*(longlong *)(param_1 + 0x68) - lVar2) / 0x68));

  }

  return;

}




