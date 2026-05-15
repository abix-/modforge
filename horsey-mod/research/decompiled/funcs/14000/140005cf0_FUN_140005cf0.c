// Address: 0x140005cf0
// Ghidra name: FUN_140005cf0
// ============ 0x140005cf0 FUN_140005cf0 (size=260) ============


void FUN_140005cf0(longlong *param_1)



{

  longlong lVar1;

  longlong lVar2;

  longlong lVar3;

  ulonglong uVar4;

  uint uVar5;

  ulonglong uVar6;

  

  uVar4 = 0;

  lVar2 = param_1[0x3264];

  while (lVar2 != 0) {

    lVar1 = *(longlong *)(lVar2 + 0x68);

    lVar3 = *(longlong *)(lVar2 + 0x70);

    while (lVar2 = lVar1, lVar3 != 0) {

      lVar2 = *(longlong *)(lVar3 + 8);

      *(undefined4 *)(lVar3 + 0x30) = 0;

      FUN_140007ca0(lVar3,param_1);

      lVar3 = lVar2;

    }

  }

  thunk_FUN_1402e9a80(param_1[0x325a]);

  thunk_FUN_1402e9a80(param_1[0x325c]);

  thunk_FUN_1402e9a80(param_1[0x3255]);

  if ((int)param_1[0x3210] != 0) {

    FID_conflict__assert

              (L"m_index == 0",L"C:\\dev\\Box2d2\\Box2D\\Common\\b2StackAllocator.cpp",0x20);

  }

  if ((int)param_1[0x3252] != 0) {

    FID_conflict__assert

              (L"m_entryCount == 0",L"C:\\dev\\Box2d2\\Box2D\\Common\\b2StackAllocator.cpp",0x21);

  }

  uVar6 = uVar4;

  if (0 < (int)param_1[1]) {

    do {

      thunk_FUN_1402e9a80(*(undefined8 *)(uVar4 + 8 + *param_1));

      uVar5 = (int)uVar6 + 1;

      uVar4 = uVar4 + 0x10;

      uVar6 = (ulonglong)uVar5;

    } while ((int)uVar5 < (int)param_1[1]);

  }

  thunk_FUN_1402e9a80(*param_1);

  return;

}




