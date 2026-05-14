// Address: 0x140170800
// Ghidra name: FUN_140170800
// ============ 0x140170800 FUN_140170800 (size=191) ============


ulonglong FUN_140170800(longlong param_1,undefined4 param_2,undefined4 param_3)



{

  code *pcVar1;

  longlong lVar2;

  char cVar3;

  ulonglong uVar4;

  

  if (DAT_1403fc410 == 0) {

    uVar4 = FUN_1401730c0();

    return uVar4 & 0xffffffffffffff00;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar3 = FUN_1401aa7c0(param_1,1), cVar3 != '\0')))) {

    lVar2 = DAT_1403fc410;

    *(undefined4 *)(param_1 + 0x38) = param_2;

    *(undefined4 *)(param_1 + 0x3c) = param_3;

    pcVar1 = *(code **)(lVar2 + 0x80);

    if (pcVar1 != (code *)0x0) {

      (*pcVar1)(lVar2,param_1);

    }

    uVar4 = FUN_140172190(param_1,*(undefined4 *)(param_1 + 0x84),*(undefined4 *)(param_1 + 0x88));

    return uVar4;

  }

  uVar4 = FUN_14012e850("Invalid window");

  return uVar4 & 0xffffffffffffff00;

}




