// Address: 0x140156430
// Ghidra name: FUN_140156430
// ============ 0x140156430 FUN_140156430 (size=376) ============


undefined8 FUN_140156430(longlong param_1,longlong param_2,longlong param_3,int param_4)



{

  longlong lVar1;

  char cVar2;

  undefined8 uVar3;

  undefined8 local_18;

  int local_10;

  int local_c;

  

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar2 = FUN_1401aa7c0(param_1,3), cVar2 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","texture");

  }

  else {

    if (param_3 == 0) {

      uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","pixels");

      return uVar3;

    }

    if (param_4 == 0) {

      uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","pitch");

      return uVar3;

    }

    local_10 = *(int *)(param_1 + 4);

    local_18 = 0;

    local_c = *(int *)(param_1 + 8);

    if ((((param_2 != 0) && (cVar2 = FUN_140185790(param_2,&local_18,&local_18), cVar2 == '\0')) ||

        (local_10 == 0)) || (local_c == 0)) {

      return 1;

    }

    if (*(longlong *)(param_1 + 0x100) != 0) {

      uVar3 = FUN_1401560b0(param_1,&local_18,param_3,param_4);

      return uVar3;

    }

    if (*(longlong *)(param_1 + 0xf0) != 0) {

      uVar3 = FUN_140155fb0(param_1,&local_18,param_3,param_4);

      return uVar3;

    }

    if (*(longlong *)(param_1 + 0xf8) != 0) {

      uVar3 = FUN_140155e20(param_1,&local_18,param_3,param_4);

      return uVar3;

    }

    lVar1 = *(longlong *)(param_1 + 0x10);

    cVar2 = FUN_140149dc0(param_1);

    if (cVar2 != '\0') {

      uVar3 = (**(code **)(lVar1 + 0x90))(lVar1,param_1,&local_18,param_3,param_4);

      return uVar3;

    }

  }

  return 0;

}




