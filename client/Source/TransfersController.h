/**
 * Copyright (c) 2010, 2012, Pecunia Project. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the
 * License.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301  USA
 */

#import <Cocoa/Cocoa.h>

#import "Transfer.h"
#import "TransfersListview.h"
#import "TransferTemplatesListview.h"

@class TransactionController;
@class TransfersController;
@class TransferFormularView;

@class CalendarWindow;
@class DragImageView;
@class DeleteImageView;

@interface TransferTemplateDragDestination : NSView
{
@private
    BOOL formularVisible;
    NSString *currentDragDataType;
}

@property (nonatomic, assign) TransfersController *controller;

- (NSRect)dropTargetFrame;
- (void)hideFormular;
- (void)showFormular;

@end

@interface TransfersController : NSObject <NSWindowDelegate, NSTextFieldDelegate, TransfersDragDelegate>
{
    IBOutlet NSView                 *mainView;
	IBOutlet NSArrayController      *finishedTransfers;
	IBOutlet NSArrayController      *pendingTransfers;
	IBOutlet NSTableView            *transferView;
    IBOutlet NSTextField            *selAmountField;
	IBOutlet TransactionController  *transactionController;
    IBOutlet TransfersListView      *finishedTransfersListView;
    IBOutlet TransfersListView      *pendingTransfersListView;
    IBOutlet TransferTemplatesListView *transferTemplateListView;
    IBOutlet TransferTemplateDragDestination *rightPane;

    IBOutlet NSTextField   *titleText;
    IBOutlet NSTextField   *receiverText;
    IBOutlet NSPopUpButton *sourceAccountSelector;
    IBOutlet NSPopUpButton *targetAccountSelector;
    IBOutlet NSComboBox    *receiverComboBox;
    IBOutlet NSTextField   *amountCurrencyText;
    IBOutlet NSTextField   *accountText;
    IBOutlet NSTextField   *accountNumber;
    IBOutlet NSTextField   *bankCodeText;
    IBOutlet NSTextField   *bankCode;
    IBOutlet NSTextField   *saldoText;
    IBOutlet NSTextField   *saldoCurrencyText;
    IBOutlet NSTextField   *targetCountryText;
    IBOutlet NSPopUpButton *targetCountrySelector;
    IBOutlet NSTextField   *feeText;
    IBOutlet NSPopUpButton *feeSelector;
    IBOutlet NSTextField   *bankDescription;
    
    IBOutlet NSTextField   *executionText;
    IBOutlet NSButton      *executeImmediatelyRadioButton;
    IBOutlet NSTextField   *executeImmediatelyText;
    IBOutlet NSButton      *executeAtDateRadioButton;
    IBOutlet NSDatePicker  *executionDatePicker;
    IBOutlet NSView        *calendarView;
    IBOutlet NSButton      *calendarButton;
    IBOutlet NSDatePicker  *calendar;
    
    IBOutlet NSButton      *queueItButton;
    IBOutlet NSButton      *doItButton;
    IBOutlet NSButton      *sendTransfersButton;
    IBOutlet NSTextField   *templateName;
    
    IBOutlet DragImageView  *transferDebitImage;
    IBOutlet DragImageView  *transferInternalImage;
    IBOutlet DragImageView  *transferNormalImage;
    IBOutlet DragImageView  *transferEUImage;
    IBOutlet DragImageView  *transferSEPAImage;
    IBOutlet DeleteImageView *transferDeleteImage;
    
    IBOutlet NSPanel        *templateNameSheet;
    
@private
	NSNumberFormatter *formatter;
    CalendarWindow* calendarWindow;
}

@property (assign) IBOutlet TransferFormularView *transferFormular;
@property (nonatomic, assign) BOOL dropToEditRejected;

- (IBAction)sendTransfers: (id)sender;
- (IBAction)deleteTransfers: (id)sender;
- (IBAction)changeTransfer: (id)sender;
- (IBAction)transferDoubleClicked: (id)sender;
- (IBAction)showCalendar: (id)sender;
- (IBAction)sourceAccountChanged: (id)sender;
- (IBAction)targetAccountChanged: (id)sender;
- (IBAction)calendarChanged: (id)sender;
- (IBAction)queueTransfer: (id)sender;
- (IBAction)sendTransfer: (id)sender;
- (IBAction)saveTemplate: (id)sender;
- (IBAction)cancelCreateTemplate: (id)sender;

- (void)hideCalendarWindow;

- (void)draggingStartsFor: (TransfersListView *)sender;
- (BOOL)prepareTransferOfType: (TransferType)type;
- (BOOL)prepareEditingFromDragging: (id<NSDraggingInfo>)info;
- (BOOL)startEditingFromDragging: (id<NSDraggingInfo>)info;
- (BOOL)concludeDropDeleteOperation: (id<NSDraggingInfo>)info;
- (void)cancelEditing;
- (BOOL)editingInProgress;

- (NSView *)mainView;
- (void)prepare;
- (void)activate;
- (void)deactivate;
- (void)terminate;

@end
