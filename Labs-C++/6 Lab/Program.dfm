object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Lab6V1 (by Nemkovich)'
  ClientHeight = 384
  ClientWidth = 575
  Color = clMoneyGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 112
    Top = 8
    Width = 372
    Height = 17
    Caption = #1055#1088#1086#1075#1088#1072#1084#1084#1080#1088#1086#1074#1072#1085#1080#1077' '#1089' '#1080#1089#1087#1086#1083#1100#1079#1086#1074#1072#1085#1080#1077#1084' '#1076#1077#1088#1077#1074#1100#1077#1074' ( 6 Lab, V 1 )'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic, fsUnderline]
    ParentFont = False
  end
  object TreeView1: TTreeView
    Left = 224
    Top = 30
    Width = 346
    Height = 149
    Indent = 19
    TabOrder = 0
  end
  object Memo1: TMemo
    Left = 400
    Top = 185
    Width = 170
    Height = 192
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object StringGrid1: TStringGrid
    Left = 224
    Top = 185
    Width = 170
    Height = 192
    ColCount = 2
    DefaultColWidth = 83
    DefaultRowHeight = 26
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object Button1: TButton
    Left = 8
    Top = 185
    Width = 210
    Height = 25
    Caption = 'Add key and full name'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 8
    Top = 158
    Width = 161
    Height = 21
    TabOrder = 4
    TextHint = 'Full name'
  end
  object Edit2: TEdit
    Left = 175
    Top = 158
    Width = 42
    Height = 21
    TabOrder = 5
    TextHint = 'Key'
  end
  object Button2: TButton
    Left = 8
    Top = 352
    Width = 210
    Height = 25
    Caption = 'Exit'
    TabOrder = 6
    OnClick = Button2Click
  end
  object Button5: TButton
    Left = 8
    Top = 31
    Width = 210
    Height = 25
    Caption = 'Show Tree in Memo'
    TabOrder = 7
    OnClick = Button5Click
  end
  object Button7: TButton
    Left = 8
    Top = 62
    Width = 161
    Height = 25
    Caption = 'Delete key from Tree'
    TabOrder = 8
    OnClick = Button7Click
  end
  object Edit4: TEdit
    Left = 176
    Top = 64
    Width = 42
    Height = 21
    TabOrder = 9
    TextHint = 'Key'
  end
  object Button8: TButton
    Left = 8
    Top = 93
    Width = 210
    Height = 25
    Caption = 'Balance Tree'
    TabOrder = 10
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 8
    Top = 125
    Width = 161
    Height = 25
    Caption = 'Find key and show info'
    TabOrder = 11
    OnClick = Button9Click
  end
  object Edit5: TEdit
    Left = 175
    Top = 127
    Width = 42
    Height = 21
    TabOrder = 12
    TextHint = 'Key'
  end
  object Button3: TButton
    Left = 8
    Top = 216
    Width = 210
    Height = 25
    Caption = 'Swap the min and max keys'
    TabOrder = 13
    OnClick = Button3Click
  end
end
