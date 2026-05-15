// Address: 0x140281e30
// Ghidra name: FUN_140281e30
// ============ 0x140281e30 FUN_140281e30 (size=231) ============


undefined1 FUN_140281e30(longlong param_1)



{

  longlong lVar1;

  char cVar2;

  undefined1 uVar3;

  ushort uVar4;

  undefined1 local_48 [5];

  undefined1 local_43;

  char local_42;

  undefined1 local_39;

  undefined1 local_38;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  cVar2 = FUN_1402823d0();

  if (cVar2 == '\0') {

    return 0;

  }

  cVar2 = FUN_140280e70(param_1,1,local_48,0x40);

  if (cVar2 == '\0') {

    uVar3 = FUN_14012e850("Couldn\'t get controller info");

    return uVar3;

  }

  *(ushort *)(lVar1 + 0x10) = CONCAT11(local_39,local_38);

  if (*(short *)(param_1 + 0x22) == 0x2401) {

    uVar4 = 0x7141;

  }

  else {

    if (*(short *)(param_1 + 0x22) != 0x2501) goto LAB_140281eda;

    uVar4 = 0x7031;

  }

  if (CONCAT11(local_39,local_38) < uVar4) {

    uVar3 = FUN_14012e850("Unsupported firmware version");

    return uVar3;

  }

LAB_140281eda:

  if (local_42 == '\x01') {

    *(undefined1 *)(lVar1 + 0xd) = 0;

  }

  else if (local_42 == '\x02') {

    *(undefined1 *)(lVar1 + 0xd) = 1;

  }

  *(undefined1 *)(lVar1 + 8) = local_43;

  FUN_140281f80(param_1);

  FUN_140282420(param_1);

  return 1;

}




