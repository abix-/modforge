// Address: 0x14022c7f0
// Ghidra name: FUN_14022c7f0
// ============ 0x14022c7f0 FUN_14022c7f0 (size=79) ============


void FUN_14022c7f0(longlong param_1)



{

  longlong lVar1;

  BOOL BVar2;

  int iVar3;

  tagRECT local_18;

  

  lVar1 = *(longlong *)(param_1 + 0x188);

  BVar2 = GetClipCursor(&local_18);

  if (BVar2 != 0) {

    iVar3 = memcmp(&local_18,(void *)(lVar1 + 0x8c),0x10);

    if (iVar3 == 0) {

      ClipCursor((RECT *)0x0);

      *(undefined8 *)(lVar1 + 0x8c) = 0;

      *(undefined8 *)(lVar1 + 0x94) = 0;

    }

  }

  return;

}




