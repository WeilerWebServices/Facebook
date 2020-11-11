/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.params;

import com.facebook.nifty.client.RequestChannel;
import com.facebook.swift.codec.*;
import com.facebook.swift.service.*;
import com.facebook.swift.service.metadata.*;
import com.facebook.swift.transport.client.*;
import com.google.common.util.concurrent.ListenableFuture;
import java.io.*;
import java.lang.reflect.Method;
import java.util.*;
import org.apache.thrift.ProtocolId;
import reactor.core.publisher.Mono;

@SwiftGenerated
public class NestedContainersAsyncClientImpl extends AbstractThriftClient implements NestedContainers.Async {

    // Method Handlers
    private ThriftMethodHandler mapListMethodHandler;
    private ThriftMethodHandler mapSetMethodHandler;
    private ThriftMethodHandler listMapMethodHandler;
    private ThriftMethodHandler listSetMethodHandler;
    private ThriftMethodHandler turtlesMethodHandler;

    // Method Exceptions
    private static final Class[] mapListExceptions = new Class[] {
        org.apache.thrift.TException.class};
    private static final Class[] mapSetExceptions = new Class[] {
        org.apache.thrift.TException.class};
    private static final Class[] listMapExceptions = new Class[] {
        org.apache.thrift.TException.class};
    private static final Class[] listSetExceptions = new Class[] {
        org.apache.thrift.TException.class};
    private static final Class[] turtlesExceptions = new Class[] {
        org.apache.thrift.TException.class};

    public NestedContainersAsyncClientImpl(
        RequestChannel channel,
        Map<Method, ThriftMethodHandler> methods,
        Map<String, String> headers,
        Map<String, String> persistentHeaders,
        List<? extends ThriftClientEventHandler> eventHandlers) {
      super(channel, headers, persistentHeaders, eventHandlers);

      Map<String, ThriftMethodHandler> methodHandlerMap = new HashMap<>();
      methods.forEach(
          (key, value) -> {
            methodHandlerMap.put(key.getName(), value);
          });

      // Set method handlers
      mapListMethodHandler = methodHandlerMap.get("mapList");
      mapSetMethodHandler = methodHandlerMap.get("mapSet");
      listMapMethodHandler = methodHandlerMap.get("listMap");
      listSetMethodHandler = methodHandlerMap.get("listSet");
      turtlesMethodHandler = methodHandlerMap.get("turtles");
    }

    public NestedContainersAsyncClientImpl(
        Map<String, String> headers,
        Map<String, String> persistentHeaders,
        Mono<? extends RpcClient> rpcClient,
        ThriftServiceMetadata serviceMetadata,
        ThriftCodecManager codecManager,
        ProtocolId protocolId,
        Map<Method, ThriftMethodHandler> methods) {
      super(headers, persistentHeaders, rpcClient, serviceMetadata, codecManager, protocolId);

      Map<String, ThriftMethodHandler> methodHandlerMap = new HashMap<>();
      methods.forEach(
          (key, value) -> {
            methodHandlerMap.put(key.getName(), value);
          });

      // Set method handlers
      mapListMethodHandler = methodHandlerMap.get("mapList");
      mapSetMethodHandler = methodHandlerMap.get("mapSet");
      listMapMethodHandler = methodHandlerMap.get("listMap");
      listSetMethodHandler = methodHandlerMap.get("listSet");
      turtlesMethodHandler = methodHandlerMap.get("turtles");
    }

    @java.lang.Override
    public void close() {
        super.close();
    }


    @java.lang.Override
    public ListenableFuture<Void> mapList(
        Map<Integer, List<Integer>> foo) {
        try {
          return (ListenableFuture<Void>) execute(mapListMethodHandler, mapListExceptions, foo);
        } catch (Throwable t) {
          throw new RuntimeTException(t.getMessage(), t);
        }
    }

    @java.lang.Override
    public ListenableFuture<Void> mapSet(
        Map<Integer, Set<Integer>> foo) {
        try {
          return (ListenableFuture<Void>) execute(mapSetMethodHandler, mapSetExceptions, foo);
        } catch (Throwable t) {
          throw new RuntimeTException(t.getMessage(), t);
        }
    }

    @java.lang.Override
    public ListenableFuture<Void> listMap(
        List<Map<Integer, Integer>> foo) {
        try {
          return (ListenableFuture<Void>) execute(listMapMethodHandler, listMapExceptions, foo);
        } catch (Throwable t) {
          throw new RuntimeTException(t.getMessage(), t);
        }
    }

    @java.lang.Override
    public ListenableFuture<Void> listSet(
        List<Set<Integer>> foo) {
        try {
          return (ListenableFuture<Void>) execute(listSetMethodHandler, listSetExceptions, foo);
        } catch (Throwable t) {
          throw new RuntimeTException(t.getMessage(), t);
        }
    }

    @java.lang.Override
    public ListenableFuture<Void> turtles(
        List<List<Map<Integer, Map<Integer, Set<Integer>>>>> foo) {
        try {
          return (ListenableFuture<Void>) execute(turtlesMethodHandler, turtlesExceptions, foo);
        } catch (Throwable t) {
          throw new RuntimeTException(t.getMessage(), t);
        }
    }


    public ListenableFuture<Void> mapList(
        Map<Integer, List<Integer>> foo,
        RpcOptions rpcOptions) {
        try {
          return (ListenableFuture<Void>) executeWithOptions(mapListMethodHandler, mapListExceptions, rpcOptions, foo);
        } catch (Throwable t) {
          throw new RuntimeTException(t.getMessage(), t);
        }
    }

    public ListenableFuture<Void> mapSet(
        Map<Integer, Set<Integer>> foo,
        RpcOptions rpcOptions) {
        try {
          return (ListenableFuture<Void>) executeWithOptions(mapSetMethodHandler, mapSetExceptions, rpcOptions, foo);
        } catch (Throwable t) {
          throw new RuntimeTException(t.getMessage(), t);
        }
    }

    public ListenableFuture<Void> listMap(
        List<Map<Integer, Integer>> foo,
        RpcOptions rpcOptions) {
        try {
          return (ListenableFuture<Void>) executeWithOptions(listMapMethodHandler, listMapExceptions, rpcOptions, foo);
        } catch (Throwable t) {
          throw new RuntimeTException(t.getMessage(), t);
        }
    }

    public ListenableFuture<Void> listSet(
        List<Set<Integer>> foo,
        RpcOptions rpcOptions) {
        try {
          return (ListenableFuture<Void>) executeWithOptions(listSetMethodHandler, listSetExceptions, rpcOptions, foo);
        } catch (Throwable t) {
          throw new RuntimeTException(t.getMessage(), t);
        }
    }

    public ListenableFuture<Void> turtles(
        List<List<Map<Integer, Map<Integer, Set<Integer>>>>> foo,
        RpcOptions rpcOptions) {
        try {
          return (ListenableFuture<Void>) executeWithOptions(turtlesMethodHandler, turtlesExceptions, rpcOptions, foo);
        } catch (Throwable t) {
          throw new RuntimeTException(t.getMessage(), t);
        }
    }
}