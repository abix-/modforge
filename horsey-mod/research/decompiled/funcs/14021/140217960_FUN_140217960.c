// Address: 0x140217960
// Ghidra name: FUN_140217960
// ============ 0x140217960 FUN_140217960 (size=258) ============


longlong FUN_140217960(longlong *param_1,longlong param_2,ulonglong param_3)



{

  longlong lVar1;

  ulonglong uVar2;

  longlong lVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  

  lVar3 = *param_1;

  lVar1 = *(longlong *)(lVar3 + 0x40);

  if (param_3 <= (ulonglong)(*(longlong *)(lVar3 + 0x48) - lVar1)) {

    *(ulonglong *)(lVar3 + 0x40) = lVar1 + param_3;

    return *(longlong *)(lVar3 + 0x38) + lVar1;

  }

  uVar5 = 0;

  while( true ) {

    uVar2 = *(longlong *)(lVar3 + 0x48) - *(longlong *)(lVar3 + 0x40);

    uVar4 = param_3 - uVar5;

    if (uVar2 <= param_3 - uVar5) {

      uVar4 = uVar2;

    }

    FUN_1402f8e20(uVar5 + param_2,*(longlong *)(lVar3 + 0x38) + *(longlong *)(lVar3 + 0x40),uVar4);

    *(longlong *)(lVar3 + 0x40) = *(longlong *)(lVar3 + 0x40) + uVar4;

    uVar5 = uVar5 + uVar4;

    if (uVar5 == param_3) {

      return param_2;

    }

    if (*(char *)(lVar3 + 0x18) != '\0') {

      FUN_14012e850("Reading past end of flushed track");

      return 0;

    }

    lVar1 = *(longlong *)(lVar3 + 0x20);

    if (lVar1 == 0) break;

    FUN_140218330(param_1,*(undefined8 *)(lVar3 + 0x38),*(undefined8 *)(lVar3 + 0x48));

    *param_1 = lVar1;

    FUN_140217700(param_1,lVar3);

    lVar3 = lVar1;

  }

  FUN_14012e850("Reading past end of incomplete track");

  return 0;

}




