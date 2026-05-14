// Address: 0x140175d80
// Ghidra name: FUN_140175d80
// ============ 0x140175d80 FUN_140175d80 (size=101) ============


ulonglong FUN_140175d80(longlong param_1,ushort *param_2)



{

  ulonglong in_RAX;

  

  if (param_1 == 0) {

LAB_140175dc5:

    in_RAX = FUN_14012e850("Parameter \'%s\' is invalid","haptic");

  }

  else {

    if (DAT_1403e3d60 != '\0') {

      in_RAX = FUN_1401aa7c0(param_1,6);

      if ((char)in_RAX == '\0') goto LAB_140175dc5;

    }

    if (param_2 != (ushort *)0x0) {

      return (ulonglong)

             CONCAT11((char)(*param_2 >> 8),(*(uint *)(param_1 + 0x20) & (uint)*param_2) != 0);

    }

  }

  return in_RAX & 0xffffffffffffff00;

}




