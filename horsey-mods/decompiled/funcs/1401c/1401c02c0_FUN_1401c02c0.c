// Address: 0x1401c02c0
// Ghidra name: FUN_1401c02c0
// ============ 0x1401c02c0 FUN_1401c02c0 (size=258) ============


ulonglong FUN_1401c02c0(longlong param_1,undefined8 param_2,int param_3)



{

  char cVar1;

  byte bVar2;

  longlong lVar3;

  ulonglong uVar4;

  undefined1 local_68 [56];

  undefined8 local_30;

  undefined8 local_20;

  undefined4 local_18;

  

  lVar3 = FUN_1401baca0(param_2);

  bVar2 = 0;

  if (lVar3 == 0) {

    if (*(char *)(param_1 + 0x57c) != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,&DAT_14039bf30,"Must claim window before querying present mode support!");

    }

    uVar4 = FUN_14012e850(&DAT_14039bf30,"Must claim window before querying present mode support!");

    uVar4 = uVar4 & 0xffffffffffffff00;

  }

  else if (*(longlong *)(lVar3 + 0x28) == 0) {

    if (*(char *)(param_1 + 0x57c) != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,&DAT_14039bf30,"Window has no Vulkan surface");

    }

    uVar4 = FUN_14012e850(&DAT_14039bf30,"Window has no Vulkan surface");

    uVar4 = uVar4 & 0xffffffffffffff00;

  }

  else {

    cVar1 = FUN_1401bc440(param_1,*(undefined8 *)(param_1 + 8),*(longlong *)(lVar3 + 0x28),local_68)

    ;

    if (cVar1 != '\0') {

      bVar2 = FUN_1401bf320(*(undefined4 *)(&DAT_1403e3eb0 + (longlong)param_3 * 4),local_20,

                            local_18);

      FUN_1401841e0(local_30);

      FUN_1401841e0(local_20);

    }

    uVar4 = (ulonglong)bVar2;

  }

  return uVar4;

}




