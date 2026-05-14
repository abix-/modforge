// Address: 0x140188300
// Ghidra name: FUN_140188300
// ============ 0x140188300 FUN_140188300 (size=92) ============


ulonglong FUN_140188300(undefined8 param_1,undefined8 param_2)



{

  byte bVar1;

  ulonglong uVar2;

  longlong lVar3;

  undefined1 local_28 [32];

  

  uVar2 = FUN_1401871e0(local_28,param_1);

  if ((char)uVar2 != '\0') {

    lVar3 = FUN_14012c130(param_2,&DAT_14030a390);

    uVar2 = 0;

    if (lVar3 != 0) {

      bVar1 = FUN_140187cc0(local_28,lVar3,1);

      FUN_1401871c0(local_28);

      return (ulonglong)bVar1;

    }

  }

  return uVar2 & 0xffffffffffffff00;

}




