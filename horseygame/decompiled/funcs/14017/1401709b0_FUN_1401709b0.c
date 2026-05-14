// Address: 0x1401709b0
// Ghidra name: FUN_1401709b0
// ============ 0x1401709b0 FUN_1401709b0 (size=208) ============


ulonglong FUN_1401709b0(longlong param_1,char param_2)



{

  char cVar1;

  ulonglong uVar2;

  

  if (DAT_1403fc410 == 0) {

    uVar2 = FUN_1401730c0();

    return uVar2 & 0xffffffffffffff00;

  }

  if ((param_1 != 0) &&

     ((DAT_1403e3d60 == '\0' || (cVar1 = FUN_1401aa7c0(param_1,1), cVar1 != '\0')))) {

    uVar2 = (ulonglong)

            CONCAT31((uint3)(*(uint *)(param_1 + 0x48) >> 0x1d),

                     (char)(*(uint *)(param_1 + 0x48) >> 0x15)) & 0xffffffffffffff01;

    if ((param_2 != '\0') != SUB81(uVar2,0)) {

      uVar2 = 0;

      if (*(code **)(DAT_1403fc410 + 0x188) != (code *)0x0) {

        uVar2 = (**(code **)(DAT_1403fc410 + 0x188))(DAT_1403fc410,param_1);

        if ((char)uVar2 == '\0') goto LAB_140170a73;

        if (param_2 != '\0') {

          uVar2 = *(ulonglong *)(param_1 + 0x48) | 0x200000;

          *(ulonglong *)(param_1 + 0x48) = uVar2;

          return CONCAT71((int7)(uVar2 >> 8),1);

        }

        uVar2 = *(ulonglong *)(param_1 + 0x48) & 0xffffffffffdfffff;

        *(ulonglong *)(param_1 + 0x48) = uVar2;

      }

    }

    return CONCAT71((int7)(uVar2 >> 8),1);

  }

  uVar2 = FUN_14012e850("Invalid window");

LAB_140170a73:

  return uVar2 & 0xffffffffffffff00;

}




