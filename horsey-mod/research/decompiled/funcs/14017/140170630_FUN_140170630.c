// Address: 0x140170630
// Ghidra name: FUN_140170630
// ============ 0x140170630 FUN_140170630 (size=216) ============


bool FUN_140170630(longlong param_1,undefined4 *param_2,undefined4 param_3)



{

  longlong lVar1;

  char cVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return false;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar2 = FUN_1401aa7c0(param_1,1), cVar2 != '\0')))) {

    lVar1 = DAT_1403fc410;

    if (param_2 == (undefined4 *)0x0) {

      uVar3 = 0;

      uVar4 = 0;

      uVar5 = 0;

      uVar6 = 0;

      param_3 = 0;

    }

    else {

      uVar3 = *param_2;

      uVar4 = param_2[1];

      uVar5 = param_2[2];

      uVar6 = param_2[3];

    }

    *(undefined4 *)(param_1 + 0x13c) = uVar3;

    *(undefined4 *)(param_1 + 0x140) = uVar4;

    *(undefined4 *)(param_1 + 0x144) = uVar5;

    *(undefined4 *)(param_1 + 0x148) = uVar6;

    *(undefined4 *)(param_1 + 0x14c) = param_3;

    if ((lVar1 != 0) && (*(code **)(lVar1 + 0x270) != (code *)0x0)) {

      cVar2 = (**(code **)(lVar1 + 0x270))(lVar1,param_1);

      return cVar2 != '\0';

    }

    return true;

  }

  FUN_14012e850("Invalid window");

  return false;

}




