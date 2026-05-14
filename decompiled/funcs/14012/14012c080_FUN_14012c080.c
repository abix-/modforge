// Address: 0x14012c080
// Ghidra name: FUN_14012c080
// ============ 0x14012c080 FUN_14012c080 (size=173) ============


longlong FUN_14012c080(void)



{

  longlong *plVar1;

  longlong lVar2;

  undefined8 local_48;

  undefined *local_40;

  undefined1 *local_38;

  code *local_30;

  code *local_28;

  undefined8 local_20;

  code *local_18;

  

  plVar1 = (longlong *)FUN_1401841a0(1,0x30);

  if (plVar1 == (longlong *)0x0) {

    return 0;

  }

  local_20 = 0;

  local_48 = 0x38;

  local_40 = &DAT_14012cf80;

  local_38 = &LAB_14012cf70;

  local_30 = FUN_14012ce50;

  local_28 = FUN_14012cf90;

  local_18 = FUN_14012ce10;

  lVar2 = FUN_14012c690(&local_48,plVar1);

  if (lVar2 != 0) {

    *plVar1 = lVar2;

    return lVar2;

  }

  FUN_1401841e0(plVar1);

  return 0;

}




