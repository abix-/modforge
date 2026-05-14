// Address: 0x140171820
// Ghidra name: FUN_140171820
// ============ 0x140171820 FUN_140171820 (size=209) ============


ulonglong FUN_140171820(longlong param_1,float param_2)



{

  char cVar1;

  ulonglong uVar2;

  float fVar3;

  

  if (DAT_1403fc410 == 0) {

    uVar2 = FUN_1401730c0();

    return uVar2 & 0xffffffffffffff00;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar1 = FUN_1401aa7c0(param_1,1), cVar1 != '\0')))) {

    if (*(code **)(DAT_1403fc410 + 0xa0) != (code *)0x0) {

      fVar3 = 0.0;

      if ((0.0 <= param_2) && (fVar3 = DAT_14039ca44, param_2 <= DAT_14039ca44)) {

        fVar3 = param_2;

      }

      uVar2 = (**(code **)(DAT_1403fc410 + 0xa0))(DAT_1403fc410,param_1,fVar3);

      if ((char)uVar2 != '\0') {

        *(float *)(param_1 + 0xf8) = fVar3;

      }

      return uVar2;

    }

    uVar2 = FUN_14012e850("That operation is not supported");

    return uVar2;

  }

  uVar2 = FUN_14012e850("Invalid window");

  return uVar2 & 0xffffffffffffff00;

}




