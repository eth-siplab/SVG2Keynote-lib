#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>
#include <headers/keynote.h>

@interface CPP_Wrapper : NSObject
- (NSData *)generateClipboardForTSPNativeData:(NSString *)svgStringData;
- (NSData *)generateClipboardMetadata;
@end

@implementation CPP_Wrapper

- (NSData *)generateClipboardForTSPNativeData:(NSString *)svgStringData {
    std::string stddata([svgStringData UTF8String]);
    std::string response = generateTSPNativeDataClipboardFromSVG(stddata);
    return [[NSData alloc] initWithBytes:response.data() length:response.length()];
}

- (NSData *)generateClipboardMetadata {
    std::string response = generateTSPNativeMetadataClipboard();
    return [[NSData alloc] initWithBytes:response.data() length:response.length()];
}
@end

int main(int argc, const char *argv[]) {
    @autoreleasepool {
        CPP_Wrapper *wrapper = [[CPP_Wrapper alloc] init];

        NSFileHandle *stdinHandle = [NSFileHandle fileHandleWithStandardInput];
        NSData *inputData = [stdinHandle readDataToEndOfFile];
        NSString *inputString = [[NSString alloc] initWithData:inputData encoding:NSUTF8StringEncoding];

        if ([inputString length] == 0) {
            fprintf(stderr, "Error: No input SVG data received from stdin.\n");
            return 1;
        }

        NSData *clipboardData = [wrapper generateClipboardForTSPNativeData:inputString];
        NSData *clipboardMetadata = [wrapper generateClipboardMetadata];

        if ([clipboardData length] == 0) {
            fprintf(stderr, "Error: Failed to generate TSPNativeData from SVG.\n");
            return 1;
        }

        if ([clipboardMetadata length] == 0) {
            fprintf(stderr, "Error: Failed to generate TSPNativeMetadata.\n");
            return 1;
        }

        NSPasteboard *pasteboard = [NSPasteboard generalPasteboard];
        [pasteboard clearContents];

        [pasteboard setData:clipboardData forType:@"com.apple.iWork.TSPNativeData"];
        [pasteboard setData:clipboardMetadata forType:@"com.apple.iWork.TSPNativeMetadata"];
        // As per format_documentation.md, this type must be present.
        [pasteboard setData:[NSData data] forType:@"com.apple.iWork.pasteboardState.hasNativeDrawables"];
    }
    return 0;
}
