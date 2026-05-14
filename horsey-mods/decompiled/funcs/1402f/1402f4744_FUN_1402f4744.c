// Address: 0x1402f4744
// Ghidra name: FUN_1402f4744
// ============ 0x1402f4744 FUN_1402f4744 (size=115) ============


undefined8 FUN_1402f4744(__crt_locale_pointers *param_1,uint param_2,uint param_3,byte param_4)



{

  undefined8 uVar1;

  longlong local_28;

  longlong *local_20;

  longlong local_18;

  char local_10;

  

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_28,param_1);

  if (((*(byte *)(((ulonglong)param_2 & 0xff) + 0x19 + local_18) & param_4) == 0) &&

     ((param_3 == 0 || ((param_3 & *(ushort *)(*local_20 + ((ulonglong)param_2 & 0xff) * 2)) == 0)))

     ) {

    uVar1 = 0;

  }

  else {

    uVar1 = 1;

  }

  if (local_10 != '\0') {

    *(uint *)(local_28 + 0x3a8) = *(uint *)(local_28 + 0x3a8) & 0xfffffffd;

  }

  return uVar1;

}




