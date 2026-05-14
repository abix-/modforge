// Address: 0x14016ebe0
// Ghidra name: FUN_14016ebe0
// ============ 0x14016ebe0 FUN_14016ebe0 (size=346) ============


undefined8 FUN_14016ebe0(longlong param_1,uint *param_2,uint *param_3)



{

  char cVar1;

  undefined4 uVar2;

  longlong lVar3;

  uint *puVar4;

  uint *puVar5;

  float fVar6;

  uint local_res20 [2];

  

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar1 = FUN_1401aa7c0(param_1,1), cVar1 != '\0')))) {

    puVar5 = local_res20;

    if (param_2 != (uint *)0x0) {

      puVar5 = param_2;

    }

    puVar4 = local_res20;

    if (param_3 != (uint *)0x0) {

      puVar4 = param_3;

    }

    if (*(code **)(DAT_1403fc410 + 0x98) == (code *)0x0) {

      uVar2 = FUN_14016d540(param_1);

      FUN_14016ed40(param_1,puVar5,puVar4);

      if (((*(byte *)(param_1 + 0x48) & 1) == 0) || (lVar3 = FUN_14016e1f0(param_1), lVar3 == 0)) {

        lVar3 = FUN_14016d260(uVar2);

      }

      else {

        lVar3 = FUN_14016d1d0(uVar2);

      }

      if (lVar3 != 0) {

        fVar6 = (float)thunk_FUN_1402e33f0((float)(int)*puVar5 * *(float *)(lVar3 + 0x10));

        *puVar5 = (int)fVar6;

        fVar6 = (float)thunk_FUN_1402e33f0((float)(int)*puVar4 * *(float *)(lVar3 + 0x10));

        *puVar4 = (int)fVar6;

      }

      return 1;

    }

    (**(code **)(DAT_1403fc410 + 0x98))(DAT_1403fc410,param_1,puVar5,puVar4);

    return 1;

  }

  FUN_14012e850("Invalid window");

  return 0;

}




