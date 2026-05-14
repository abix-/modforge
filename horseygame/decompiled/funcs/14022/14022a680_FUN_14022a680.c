// Address: 0x14022a680
// Ghidra name: FUN_14022a680
// ============ 0x14022a680 FUN_14022a680 (size=359) ============


void FUN_14022a680(IDropTargetVtbl *param_1,char param_2)



{

  _func_6375 *p_Var1;

  UINT UVar2;

  LPDROPTARGET pDropTarget;

  char *pcVar3;

  

  p_Var1 = param_1[7].QueryInterface;

  if (*(char *)(*(longlong *)(p_Var1 + 0xc0) + 5) == '\0') {

    DragAcceptFiles(*(HWND *)(p_Var1 + 8),(uint)(param_2 != '\0'));

    pcVar3 = "disabled";

    if (param_2 != '\0') {

      pcVar3 = "enabled";

    }

    FUN_14012e280(7,". In Accept Drag and Drop, window %u, %s Fallback WM_DROPFILES",

                  *(undefined4 *)&param_1->QueryInterface,pcVar3);

  }

  else if (param_2 == '\0') {

    if (*(longlong *)(p_Var1 + 0xd8) != 0) {

      RevokeDragDrop(*(HWND *)(p_Var1 + 8));

      FUN_140228e80(*(undefined8 *)(p_Var1 + 0xd8));

      *(undefined8 *)(p_Var1 + 0xd8) = 0;

      FUN_14012e280(7,". In Accept Drag and Drop, window %u, disabled Full OLE IDropTarget",

                    *(undefined4 *)&param_1->QueryInterface);

      return;

    }

  }

  else if (*(longlong *)(p_Var1 + 0xd8) == 0) {

    pDropTarget = (LPDROPTARGET)FUN_1401841a0(1,0x28);

    if (pDropTarget != (LPDROPTARGET)0x0) {

      pDropTarget[2].lpVtbl = param_1;

      pDropTarget->lpVtbl = (IDropTargetVtbl *)&PTR_FUN_1403e54d8;

      pDropTarget[3].lpVtbl = *(IDropTargetVtbl **)(p_Var1 + 8);

      UVar2 = RegisterClipboardFormatW(L"text/uri-list");

      *(UINT *)((longlong)&pDropTarget[4].lpVtbl + 4) = UVar2;

      UVar2 = RegisterClipboardFormatW(L"text/plain;charset=utf-8");

      *(UINT *)&pDropTarget[4].lpVtbl = UVar2;

      *(LPDROPTARGET *)(p_Var1 + 0xd8) = pDropTarget;

      FUN_140228e70(pDropTarget);

      RegisterDragDrop(*(HWND *)(p_Var1 + 8),pDropTarget);

      FUN_14012e280(7,". In Accept Drag and Drop, window %u, enabled Full OLE IDropTarget",

                    *(undefined4 *)&param_1->QueryInterface);

      return;

    }

  }

  return;

}




