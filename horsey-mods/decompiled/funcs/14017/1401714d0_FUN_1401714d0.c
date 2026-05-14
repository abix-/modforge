// Address: 0x1401714d0
// Ghidra name: FUN_1401714d0
// ============ 0x1401714d0 FUN_1401714d0 (size=290) ============


ulonglong FUN_1401714d0(longlong param_1,char param_2)



{

  longlong lVar1;

  char cVar2;

  ulonglong uVar3;

  

  if (DAT_1403fc410 == 0) {

    uVar3 = FUN_1401730c0();

    return uVar3 & 0xffffffffffffff00;

  }

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar2 = FUN_1401aa7c0(param_1,1), cVar2 == '\0')))) {

    uVar3 = FUN_14012e850("Invalid window");

    return uVar3 & 0xffffffffffffff00;

  }

  lVar1 = DAT_1403fc410;

  uVar3 = *(ulonglong *)(param_1 + 0x48);

  if ((uVar3 & 0xc0000) != 0) {

    uVar3 = FUN_14012e850("Operation invalid on popup windows");

    return uVar3 & 0xffffffffffffff00;

  }

  if (*(longlong *)(DAT_1403fc410 + 0xb0) == 0) {

    uVar3 = FUN_14012e850("That operation is not supported");

    return uVar3;

  }

  if (param_2 == '\0') {

    if ((uVar3 >> 0xc & 1) == 0) goto LAB_1401715cc;

    uVar3 = uVar3 & 0xffffffffffffefff;

  }

  else {

    if (*(longlong *)(param_1 + 0x1a8) == 0) {

      uVar3 = FUN_14012e850(

                           "Window must have a parent to enable the modal state; use SDL_SetWindowParent() to set the parent first."

                           );

      return uVar3;

    }

    uVar3 = uVar3 | 0x1000;

  }

  *(ulonglong *)(param_1 + 0x48) = uVar3;

  if ((uVar3 & 8) == 0) {

                    /* WARNING: Could not recover jumptable at 0x0001401715c9. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar3 = (**(code **)(lVar1 + 0xb0))(lVar1,param_1,param_2);

    return uVar3;

  }

LAB_1401715cc:

  return CONCAT71((int7)(uVar3 >> 8),1);

}




