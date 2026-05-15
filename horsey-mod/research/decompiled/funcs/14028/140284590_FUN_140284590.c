// Address: 0x140284590
// Ghidra name: FUN_140284590
// ============ 0x140284590 FUN_140284590 (size=182) ============


ulonglong FUN_140284590(undefined8 param_1,char *param_2,uint param_3)



{

  char cVar1;

  ulonglong uVar2;

  undefined1 local_res18 [8];

  uint *local_res20;

  char *local_18 [2];

  

  if ((int)param_3 < 1) {

    FUN_14012e850("Tried to send rumble with invalid size");

  }

  else {

    cVar1 = FUN_1402843f0();

    if (cVar1 != '\0') {

      cVar1 = FUN_1402843a0(param_1,local_18,&local_res20,local_res18);

      if (((cVar1 != '\0') && (param_3 == *local_res20)) && (*param_2 == *local_18[0])) {

        FUN_1402f8e20(local_18[0],param_2,(longlong)(int)param_3);

        FUN_140284910();

        return (ulonglong)param_3;

      }

      uVar2 = FUN_140284650(param_1,param_2,param_3);

      return uVar2;

    }

  }

  return 0xffffffff;

}




