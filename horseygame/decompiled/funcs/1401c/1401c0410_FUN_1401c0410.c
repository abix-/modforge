// Address: 0x1401c0410
// Ghidra name: FUN_1401c0410
// ============ 0x1401c0410 FUN_1401c0410 (size=297) ============


ulonglong FUN_1401c0410(longlong param_1,undefined8 param_2,int param_3)



{

  char cVar1;

  byte bVar2;

  longlong lVar3;

  ulonglong uVar4;

  IMAGE_DOS_HEADER *pIVar5;

  undefined1 local_68 [56];

  undefined8 local_30;

  undefined4 local_28;

  undefined8 local_20;

  

  lVar3 = FUN_1401baca0(param_2);

  bVar2 = 0;

  if (lVar3 == 0) {

    if (*(char *)(param_1 + 0x57c) != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,&DAT_14039bf30,

                    "Must claim window before querying swapchain composition support!");

    }

    uVar4 = FUN_14012e850(&DAT_14039bf30,

                          "Must claim window before querying swapchain composition support!");

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

      lVar3 = (longlong)param_3 * 4;

      pIVar5 = &IMAGE_DOS_HEADER_140000000;

      bVar2 = FUN_1401bf340(*(undefined4 *)(&DAT_1403e4068 + lVar3),

                            *(undefined4 *)(&DAT_1403e4088 + lVar3),local_30,local_28);

      if (bVar2 == 0) {

        bVar2 = FUN_1401bf340(*(undefined4 *)(pIVar5[0x7c80].e_program + lVar3 + 0x38));

      }

      FUN_1401841e0(local_30);

      FUN_1401841e0(local_20);

    }

    uVar4 = (ulonglong)bVar2;

  }

  return uVar4;

}




