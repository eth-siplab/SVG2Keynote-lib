import sh
from AppKit import NSPasteboard
from Foundation import NSData


def svg_to_clipboard(svg_string):
    # Call the svg2key tool
    svg2key = sh.Command('./x86_64/svg2key')
    result = svg2key(_in=svg_string.encode(), _err_to_out=False)
    ns_data = result.stdout
    ns_metadata = result.stderr

    # Send the Keynote data and metadata to the clipboard
    pasteboard = NSPasteboard.generalPasteboard()
    tsp_native_data_type = 'com.apple.iWork.TSPNativeData'
    tsp_native_metadata_type = 'com.apple.iWork.TSPNativeMetadata'
    has_native_drawables_type = 'com.apple.iWork.pasteboardState.hasNativeDrawables'

    pasteboard.declareTypes_owner_([tsp_native_data_type, tsp_native_metadata_type, has_native_drawables_type], None)

    pasteboard.setData_forType_(NSData.dataWithBytes_length_(ns_data, len(ns_data)), tsp_native_data_type)
    pasteboard.setData_forType_(NSData.dataWithBytes_length_(ns_metadata, len(ns_metadata)), tsp_native_metadata_type)
    pasteboard.setString_forType_('', has_native_drawables_type)

# Example usage
with open('demo.svg') as svg_file:
    svg_content = svg_file.read()

svg_to_clipboard(svg_content)