// Address: 0x14015e380
// Ghidra name: FUN_14015e380
// ============ 0x14015e380 FUN_14015e380 (size=210) ============


undefined8 FUN_14015e380(int param_1)



{

  char cVar1;

  longlong lVar2;

  undefined8 uVar3;

  undefined8 uVar4;

  int iVar5;

  longlong local_res10;

  

  uVar3 = 0;

  lVar2 = FUN_14015e610();

  if (lVar2 != 0) {

    cVar1 = FUN_14015ec00(param_1);

    local_res10 = 0;

    FUN_14017caa0(DAT_1403fc128);

    iVar5 = DAT_1403fc148;

    if ((param_1 != -1) && (iVar5 = param_1, param_1 == -2)) {

      iVar5 = DAT_1403fc14c;

    }

    uVar4 = DAT_1403fc130;

    if (cVar1 != '\0') {

      uVar4 = DAT_1403fc138;

    }

    FUN_1401aaff0(uVar4,iVar5,&local_res10);

    if (local_res10 == 0) {

      FUN_14012e850("Invalid audio device instance ID");

    }

    else {

      lVar2 = local_res10;

      if (cVar1 != '\0') {

        lVar2 = *(longlong *)(local_res10 + 8);

      }

      uVar3 = FUN_1401aa890(*(undefined8 *)(lVar2 + 0x48));

    }

    FUN_14017cae0(DAT_1403fc128);

    return uVar3;

  }

  FUN_14012e850("Audio subsystem is not initialized");

  return 0;

}




